#include "FloorComponent.h"
#include "TextureComponent.h"
#include "GameObject.h"

FloorComponent::FloorComponent()
{
	std::vector<glm::vec4> colorVecList; //Create a vector for every colored lane
	colorVecList.push_back(glm::vec4(255, 0, 0, 1)); //Red
	verts.push_back(Vertex::PCTN(glm::vec3(-FLOOR_WIDTH / 3, 0, FLOOR_LENGTH), colorVecList[0], glm::vec2(0, 0), glm::vec3(0, -1, 0)));
	verts.push_back(Vertex::PCTN(glm::vec3(FLOOR_WIDTH / 3, 0, FLOOR_LENGTH), colorVecList[0], glm::vec2(1, 0), glm::vec3(0, -1, 0)));
	verts.push_back(Vertex::PCTN(glm::vec3(FLOOR_WIDTH / 3, 0, 0), colorVecList[0], glm::vec2(1, 1), glm::vec3(0, -1, 0)));
	verts.push_back(Vertex::PCTN(glm::vec3(-FLOOR_WIDTH / 3, 0, 0), colorVecList[0], glm::vec2(0, 1), glm::vec3(0, -1, 0)));
}

FloorComponent::~FloorComponent()
{
}

void FloorComponent::draw()
{
	std::shared_ptr<TextureComponent> tex = gameObject->getComponent<TextureComponent>();
	if (tex != NULL)
	{
		tigl::shader->enableColor(false);
		tigl::shader->enableTexture(true);
		tex->bind();
	}
	tigl::drawVertices(GL_QUADS, verts);
	tigl::shader->enableTexture(false);
	tigl::shader->enableColor(true);
}