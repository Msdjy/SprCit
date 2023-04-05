#include "scpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include "glad/glad.h"

namespace SprCit {

	SprCit::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SC_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void SprCit::OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SC_CORE_ASSERT(status, "Failed to initialize Glad!");

	}

	void SprCit::OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}