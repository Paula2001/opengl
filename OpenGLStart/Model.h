#pragma once
namespace ModelsHeaders {
	class Model
	{
	public:
		virtual Model* setTheShape() = 0;
		virtual void drawTheShape() = 0;
	protected:
		unsigned int VBO, VAO;
	};
}
