#include "currentCourse.hpp"
#include "currentUnit.hpp"
#include "unitless.hpp"


int main()
{
    while (bbc_6_minute::CurrentCourse().Go())
    {
        bbc_6_minute::with_units_courses::CurrentUnit().DownloadCourseWithUnits();
        bbc_6_minute::unit_less_courses::Unitless().DownloadCourseWithoutUnits();
    }
}