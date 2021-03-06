// -*-c++-*- Copyright (C) 2011 osgPango Development Team
// $Id$

#include <osgPairo/GlyphLayer>

namespace osgPairo {

GlyphLayer::GlyphLayer(cairo_format_t format):
_imageFormat(format) {
}

GlyphLayer::GlyphLayer(const GlyphLayer& gl, const osg::CopyOp& copyOp):
osg::Object(gl, copyOp),
_imageFormat(gl._imageFormat) {
}

bool GlyphLayer::render(
	cairo_t*       c,
	cairo_glyph_t* glyph,
	unsigned int   width,
	unsigned int   height
) {
	if(cairo_status(c) || !glyph) return false;

	cairo_glyph_path(c, glyph, 1);
	cairo_fill(c);

	return true;
}

osg::Vec4 GlyphLayer::getExtraGlyphExtents() const {
	return osg::Vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

}
