#include <wx/image.h>
#include <wx/dir.h>

class fpsImage : private wxImage
{
public:
    fpsImage();
    fpsImage(wxString path) {m_image.Open(path)}
    ~fpsImage() {m_image.Close()}
    static 
    
private:
    wxImage m_image;
}