#include "fpsImage.hpp"

using std::vector;
using std::tuple;

tuple<int, int, vector<vector<wxRect>>> fpsImage::AuxGetOutputList(int rowsOrHeight, int colsOrWidth, fpsSplitMode mode)
{
    int width {m_image.GetWidth()},
        height {m_image.GetHeight()},
        rows, cols,                               // For rows and cols when splitting by pixel.
        s1rWidth, s1rHeight,                      // s1r: Step 1 Rectangles'
        s2rWidth, s2rHeight;                      // s2r: Step 2 Rectangles'

    //------------Split by counts-----------
    if (mode == fpsSplitMode::byCounts)
    {
        s1rWidth  = width / colsOrWidth;
        s1rHeight = height / rowsOrHeight;                    
        s2rWidth  = width - (colsOrWidth - 1) * s1rWidth;
        s2rHeight = height - (rowsOrHeight - 1) * s1rHeight;     
        rows      = rowsOrHeight;
        cols      = colsOrWidth;
    }
    // ------------Split by pixel-----------
    else
    {
        s1rHeight = rowsOrHeight;
        s1rWidth  = colsOrWidth;
        rows      = height / rowsOrHeight + 1;
        cols      = width / colsOrWidth + 1;
    }

    vector<vector<wxRect>> subRects(rows, vector<wxRect>(cols));

    if ((!s1rHeight) || (!s1rWidth))
        return make_tuple(0, 0, vector<vector<wxRect>>(0));

    // Step 1：Get (rows - 1)(cols - 1) parts splited.
    for (int i {}; i < rows - 1; ++i)
        for (int j {}; j < cols - 1; ++j)
            subRects[i][j] = wxRect(s1rWidth * j, s1rHeight * i, s1rWidth, s1rHeight);
    // Step 2：Get the last column * the last row splited.
    // In this case, we get the last row first (without the right-bottom part).
    for (int j {}; j < cols - 1; ++j)
        subRects[rows - 1][j] = wxRect(s1rWidth * j, s1rHeight * (rows - 1), s1rWidth, s2rHeight);
    // Then get the last column splited (without the right-bottom part).
    for (int i {}; i < rows - 1; ++i)
        subRects[i][cols - 1] = wxRect(s1rWidth * (cols - 1), s1rHeight * i, s2rWidth, s1rHeight);
    // Get the right-bottom part splited at last.
    subRects[rows - 1][cols - 1] = wxRect(s1rWidth * (cols - 1), s1rHeight * (rows - 1), s2rWidth, s2rHeight);
    // OK! Task is finished. Return......
    return make_tuple(rows, cols, subRects);
}
