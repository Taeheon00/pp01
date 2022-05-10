#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib,"OpenGL32.lib")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr); //���� ��� stdio���
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) //escŰ�� �������� ��
        glfwSetWindowShouldClose(window, GL_TRUE); //â�� �ݴ´�
}
int main(void)
{
    GLFWwindow* window; //window��ä ����
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) //glfw�� �ʱ�ȭ �Ͽ�, Window ������ �� �� �ִ� ���·� �������ش�.
        exit(EXIT_FAILURE); //������ ����
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL); //glfw ������â ����
    if (!window)
    {
        glfwTerminate(); //���� �޸� ����
        exit(EXIT_FAILURE); //������ ����
    }
    glfwMakeContextCurrent(window); //Double Buffer�� ����� Window�� ����ϴ� �Լ��̸�, ��ϵǸ� Thread�� �����Ǿ� ���ȴ�.(GPU�� �����۾�X ���� ���� GPU�� �����Ѵٰ� �����ϴ°�)
    glfwSetKeyCallback(window, key_callback); //Ű���� �̺�Ʈ ���� �Լ�

    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height); //������ ���� ������ ����    
    ratio = width / (float)height;

    while (!glfwWindowShouldClose(window)) //������â�� �������� Ȯ��
    {
        glClearColor(0, 0, 1, 1); //����
        glClear(GL_COLOR_BUFFER_BIT); //������� ����
        glColor3f(0.8, 1, 0.8); // ���� ������
        glBegin(GL_TRIANGLES); //�ﰢ���� �׷���
        glVertex2f(0.0, 0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents(); //���� Frame�� �Է� �� ��� �̺�Ʈ�� ��� ó�� poll=�Լ�Ȯ���ϴ��۾�
    }
    glfwDestroyWindow(window); //������â �ݱ�
    glfwTerminate(); //���� �޸� ����
    exit(EXIT_SUCCESS); //���� ����
}