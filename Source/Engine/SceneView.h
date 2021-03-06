//	VQEngine | DirectX11 Renderer
//	Copyright(C) 2018  - Volkan Ilbeyli
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
#pragma once


#include <vector>
#include <unordered_map>

struct Light;
struct DirectionalLight;
class GameObject;




using RenderList = std::vector<const GameObject*>;

using RenderListLookup = std::unordered_map<MeshID, RenderList>;
using LightRenderListLookup = std::unordered_map<const Light*, RenderList>;
using LightInstancedRenderListLookup = std::unordered_map<const Light*, RenderListLookup>;

using RenderListLookupEntry = std::pair<MeshID, RenderList>;

struct ShadowView
{

	// shadowing Lights
	std::vector<const Light*> spots;
	std::vector<const Light*> points;
	const DirectionalLight* pDirectional;

	// game obj casting shadows (=render list of directional light)
	std::vector<const GameObject*> casters;
	RenderListLookup RenderListsPerMeshType;

	// culled render lists per shadowing light
	LightRenderListLookup shadowMapRenderListLookUp;
	LightInstancedRenderListLookup shadowMapInstancedRenderListLookUp;

	void Clear()
	{
		spots.clear();
		points.clear();
		casters.clear();
		pDirectional = nullptr;
	}
};

struct SceneView
{
	XMMATRIX		view;
	XMMATRIX		viewProj;
	XMMATRIX		viewInverse;
	XMMATRIX		proj;
	XMMATRIX		projInverse;

	vec3			cameraPosition;
	bool			bIsPBRLightingUsed;
	bool			bIsDeferredRendering;
	bool			bIsIBLEnabled;
	Settings::SceneRender sceneRenderSettings;
	EnvironmentMap	environmentMap;

	// list of objects that has the renderSettings.bRender=true
	RenderList opaqueList;
	RenderList alphaList;

	// list of objects that fall within the main camera's view frustum
	RenderList culledOpaqueList;
	RenderListLookup culluedOpaqueInstancedRenderListLookup;

};