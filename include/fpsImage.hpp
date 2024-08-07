#include <wx/image.h>
#include <wx/dir.h>
#include <wx/gdicmn.h>
#include <vector>
#include <tuple>

enum class fpsSplitMode { byCounts, byPixel };

class fpsImage
{
public:
    fpsImage() {}
    fpsImage(wxString path) {m_image.LoadFile(path);}
    ~fpsImage() {}
    std::tuple<int, int, std::vector<std::vector<wxRect>>> AuxGetOutputList(int rowsOrHeight, int colsOrWidth, fpsSplitMode splitMode = fpsSplitMode::byCounts);
    void SetOutputList(std::vector<std::vector<wxRect>> list) {m_outputList = list;}
    int Split();
    bool Open(wxString path) {return m_image.LoadFile(path);}

private:
    wxImage                          m_image;
    std::vector<std::vector<wxRect>> m_outputList;
};
