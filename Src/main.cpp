#include "currentCourse.hpp"
#include "currentUnit.hpp"
#include "unitless.hpp"


int main()
{
    while (bbc_6_minute::CurrentCourse().Go())
    {
        bbc_6_minute::CurrentUnit().DownloadCourseWithUnits();
        bbc_6_minute::Unitless().DownloadCourseWithoutUnits();
    }
}