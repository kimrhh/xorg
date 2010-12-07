SECTION = "libs"
PRIORITY = "optional"
DEPENDS = "libX11${RE}-dev pixman${RE}-dev libsm${RE}-dev libpng${RE}-dev fontconfig${RE}-dev libxrender${RE}-dev"
DESCRIPTION = "Cairo graphics library"
LICENSE = "MPL LGPL"

#check for TARGET_FPU=soft and inform configure of the result so it can disable some floating points 
require cairo-fpu.inc
EXTRA_OECONF += "${@get_cairo_fpu_setting(bb, d)}"

inherit autotools pkgconfig 