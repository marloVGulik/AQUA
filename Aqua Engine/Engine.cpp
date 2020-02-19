#include "Engine.hpp"
Engine::Engine(std::string title) {
	_console = new Console(0, "logs/engine.html");
	_projection = glm::mat4(0.0f);
	_view = glm::mat4(0.0f);

	_frameCounter = 0;
	_frameCounterTemp = 0;

	_FPSestimation = 0;
	_amountOfFrameTests = 0;


	_console->log("Creating window");
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (!glfwInit()) {
		_console->error("GLFW NOT INITIATED!");
	}


	_window = new Window(800, 600, title, false);
	glfwMakeContextCurrent(_window->getWindow());
	glfwSetInputMode(_window->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		_console->error("GLEW NOT INITIATED!");
	}
	
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

	_VAID = new GLuint;
	glGenVertexArrays(1, _VAID);
	glBindVertexArray(*_VAID);

	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearColor(0.6392156862f, 0.7372549019607f, 0.90196078431372549f, 1.0f);

	_programID = glCreateProgram();
	_matrixID = glGetUniformLocation(_programID, "MVP");

	_currentTime = new double(glfwGetTime());
	_oldTime = new double(glfwGetTime());
	_deltaTime = new float(static_cast<float>((float*)_currentTime - (float*)_oldTime));

	_width = new int(0);
	_height = new int(0);
	glfwGetWindowSize(_window->getWindow(), _width, _height);
	std::cout << *_width << " " << *_height << "\n";

	_console->log("Window created, creating local scene");
	_scene = new Scene(this);
	_camera = _scene->getCamera();
	if (_console != nullptr && _window != nullptr) {
		stopLoop = false;
		_console->log("Started engine succesfully!");
	}
	else {
		_console->error("ENGINE DIDN'T START SUCCESFULLY!");
		forceStop("Window or console isn't working");
	}
}
Engine::~Engine() {
	_console->log("Total frames rendered: " + std::to_string(_frameCounter));

	glDeleteVertexArrays(1, _VAID);
	glDeleteProgram(_programID);
}

Window* Engine::getWindow()
{
	return _window;
}

Console* Engine::getConsole()
{
	return _console;
}

Scene* Engine::getScene()
{
	return _scene;
}

GLuint* Engine::getProgramID()
{
	return &_programID;
}

GLuint* Engine::getMatrixID()
{
	return &_matrixID;
}

glm::mat4 Engine::getProjection()
{
	return _projection;
}

void Engine::setProjection(glm::mat4 newProjection)
{
	_projection = newProjection;
}

glm::mat4 Engine::getView()
{
	return _view;
}

void Engine::setView(glm::mat4 newView)
{
	_view = newView;
}

void Engine::loadShaders(std::string pathV, std::string pathF){
	_console->log("Loading shader files...");
	GLuint _vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint _fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	std::string VShaderCode;
	std::ifstream VertexShaderStream(pathV, std::ios::in);
	if (VertexShaderStream.is_open()) {
		std::stringstream VFInput;
		VFInput << VertexShaderStream.rdbuf();
		VShaderCode = VFInput.str();
		VertexShaderStream.close();
	}

	std::string FShaderCode;
	std::ifstream FragmentShaderStream(pathF, std::ios::in);
	if (FragmentShaderStream.is_open()) {
		std::stringstream FFInput;
		FFInput << FragmentShaderStream.rdbuf();
		FShaderCode = FFInput.str();
		FragmentShaderStream.close();
	}

	GLint result = GL_FALSE;
	int infoLogSize;

	_console->log("Compiling shaders...");
	// Vertex shader
	char const* VSP = VShaderCode.c_str();
	glShaderSource(_vertexShaderID, 1, &VSP, NULL);
	glCompileShader(_vertexShaderID);

	glGetShaderiv(_vertexShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(_vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogSize);
	if (infoLogSize > 0) {
		std::vector<char> vertexShaderErrMsg((unsigned __int64)infoLogSize + 1);
		glGetShaderInfoLog(_vertexShaderID, infoLogSize, NULL, &vertexShaderErrMsg[0]);
		_console->error(&vertexShaderErrMsg[0]);
	}

	// Fragment shader
	char const* FSP = FShaderCode.c_str();
	glShaderSource(_fragmentShaderID, 1, &FSP, NULL);
	glCompileShader(_fragmentShaderID);

	glGetShaderiv(_fragmentShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(_fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogSize);
	if (infoLogSize > 0) {
		std::vector<char> fragmentShaderErrMsg((unsigned __int64)infoLogSize + 1);
		glGetShaderInfoLog(_fragmentShaderID, infoLogSize, NULL, &fragmentShaderErrMsg[0]);
		_console->error(&fragmentShaderErrMsg[0]);
	}

	_console->log("Creating program...");
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);
	glLinkProgram(_programID);

	glGetProgramiv(_programID, GL_LINK_STATUS, &result);
	glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &infoLogSize);
	if (infoLogSize > 0) {
		std::vector<char> progErrMsg((unsigned __int64)infoLogSize + 1);
		glGetProgramInfoLog(_programID, infoLogSize, NULL, &progErrMsg[0]);
		_console->error(&progErrMsg[0]);

		forceStop("A shader isn't working correctly!");
		return;
	}

	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);

	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
	_console->log("Done creating shaders!");

	_matrixID = glGetUniformLocation(_programID, "MVP");
}

unsigned int Engine::getFPSestimation()
{
	if (_amountOfFrameTests != 0) {
		return unsigned int(_FPSestimation / _amountOfFrameTests);
	}
	else return 0;
}

float* Engine::getDTpointer()
{
	return _deltaTime;
}

void Engine::getWindowSizes(int* width, int* height) {
	*width = *_width;
	*height = *_height;
}

bool Engine::update() {
	if (stopLoop) {
		return false;
	}

	// Delta calculation! IMPORTANT
	*_deltaTime = float(*_currentTime - *_oldTime);
	*_oldTime = *_currentTime;
	*_currentTime = glfwGetTime();

	if (_frameCounterTemp == 50) {
		//_console->log(std::to_string(fps));
		_FPSestimation += 1 / *_deltaTime;
		_amountOfFrameTests++;

		_frameCounterTemp = 0;
	}

	_matrixID = glGetUniformLocation(_programID, "MVP");


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(_programID);
	// Draw here
	_scene->updateScene();

	glfwSwapBuffers(_window->getWindow());
	glfwPollEvents();

	_frameCounter++;
	_frameCounterTemp++;
	return true;
}

void Engine::forceStop(std::string error) {
	_console->error(error);
	stopLoop = true; 
	glfwDestroyWindow(_window->getWindow());
}
