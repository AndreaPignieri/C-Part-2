#include "../Lines/lines.h"

Lines::~Lines()
{
    // Clear the lines of this object in the shared container
    if (index < allLines.size())
        allLines[index].clear();
}
