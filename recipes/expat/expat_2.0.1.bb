require expat.inc
PR = "r3"

SRC_URI =+ "file://autotools.patch;patch=1"

inherit lib_package

do_configure() {
	rm -f ${S}/conftools/libtool.m4
	touch ${S}/conftools/libtool.m4
	autotools_do_configure
}

do_install() {
	oe_runmake prefix="${D}${prefix}" \
		bindir="${D}${bindir}" \
		libdir="${D}${libdir}" \
		includedir="${D}${includedir}" \
		man1dir="${D}${mandir}/man1" \
		install
}