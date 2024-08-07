#include <wx/image.h>
#include <wx/dir.h>
#include <wx/gdicmn.h>
#include <vector>

using std::vector;

enum class fpsSplitMode { byCounts, byPixel };

class fpsImage : private wxImage
{
public:
    fpsImage();
    fpsImage(wxString path) {m_image.Open(path)}
    ~fpsImage() {m_image.Close()}
    static vector<vector<wxRect>> GetOutputList(int rowsOrHeight, int colsOrWidth, fpsSplitMode splitMode = fpsSplitMode::byCounts);
    void SetOutputList(vector<vector<wxRect>> list);
    int Split();

private:
    wxImage m_image;
}