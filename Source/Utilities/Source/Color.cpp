//	DX11Renderer - VDemo | DirectX11 Renderer
//	Copyright(C) 2016  - Volkan Ilbeyli
//
//	This program is free software : you can redistribute it and / or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program.If not, see <http://www.gnu.org/licenses/>.
//
//	Contact: volkanilbeyli@gmail.com


#include "Color.h"
#include "utils.h"

using std::make_pair;

const LinearColor LinearColor::black		= vec3(0.0f, 0.0f, 0.0f);
const LinearColor LinearColor::white		= vec3(1.0f, 1.0f, 1.0f);
const LinearColor LinearColor::red			= vec3(1.0f, 0.0f, 0.0f);
const LinearColor LinearColor::green		= vec3(0.0f, 1.0f, 0.0f);
const LinearColor LinearColor::blue			= vec3(0.0f, 0.0f, 1.0f);
const LinearColor LinearColor::yellow		= vec3(1.0f, 1.0f, 0.0f);
const LinearColor LinearColor::magenta		= vec3(1.0f, 0.0f, 1.0f);
const LinearColor LinearColor::cyan			= vec3(0.0f, 1.0f, 1.0f);
const LinearColor LinearColor::gray			= vec3(0.2f, 0.2f, 0.2f);
const LinearColor LinearColor::light_gray	= vec3(0.45f, 0.45f, 0.45f);
const LinearColor LinearColor::orange		= vec3(1.0f, 0.5f, 0.0f);
const LinearColor LinearColor::purple		= vec3(0.31f, 0.149f, 0.513f);

const LinearColor::ColorPalette LinearColor::s_palette = {
	LinearColor::black,		LinearColor::white,
	LinearColor::red,		LinearColor::green,			LinearColor::blue,
	LinearColor::yellow,	LinearColor::magenta,		LinearColor::cyan,
	LinearColor::gray,		LinearColor::light_gray,
	LinearColor::orange,	LinearColor::purple
};


;

LinearColor::LinearColor() 
	: 
	value(white.Value())
{}


//const ColorPalette Color::Palette()
//{
//	return s_palette;
//}

const LinearColor::ColorPalette LinearColor::Palette()
{
	return s_palette;
}

vec3 LinearColor::RandColorF3()
{
	size_t i = RandU(0, Palette().size());
	return s_palette[i].Value();
}

XMVECTOR LinearColor::RandColorV()
{
	size_t i = RandU(0, Palette().size());
	return s_palette[i].Value();
}

LinearColor LinearColor::RandColor()
{
	return s_palette[RandU(0, Palette().size())];
}



LinearColor::LinearColor(const vec3& val)
	: 
	value(val)
{}

LinearColor::LinearColor(float r, float g, float b)
	:
	value(vec3(r, g, b))
{}

LinearColor & LinearColor::operator=(const LinearColor & rhs)
{
	this->value = rhs.Value();
	return *this;
}

LinearColor & LinearColor::operator=(const vec3& flt)
{
	this->value = flt;
	return *this;
}

//Color Color::GetColorByName(std::string colorName)
//{
//	return colorRefTable.at(colorName);
//}
//std::string Color::GetNameByColor(Color c)
//{
//	for (ColorMap::iterator it = colorRefTable.begin(); it != colorRefTable.end(); it++)
//	{
//		if (it->second.value == c.value)
//			return it->first;
//	}
//
//	return "White";
//}