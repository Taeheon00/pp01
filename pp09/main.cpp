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
    window = glfwCreateWindow(800, 480, "Simple example", NULL, NULL); //glfw ������â ����
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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    while (!glfwWindowShouldClose(window)) //������â�� �������� Ȯ��
    {
        /*glClearColor(1, 1, 1, 0); //����
        glClear(GL_COLOR_BUFFER_BIT); //������� ����
        glColor3f(0.81, 1, 0.89); // ���� ������
        glBegin(GL_TRIANGLES); //�ﰢ���� �׷���
        glVertex3f(-0.75, -0.6,0);
        glVertex3f(-0.9, -0.9,0);
        glVertex3f(-0.6, -0.9,0);
        glEnd();*/

        glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glVertex2f(0.0f, 1.0f);

        glVertex2f(1.0f, -1.0f);

        glVertex2f(-1.0f, -1.0f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 1.0f);

        glVertex2f(1.0f, -1.0f);

        glVertex2f(-1.0f, -1.0f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents(); //���� Frame�� �Է� �� ��� �̺�Ʈ�� ��� ó�� poll=�Լ�Ȯ���ϴ��۾�
    }
    glfwDestroyWindow(window); //������â �ݱ�
    glfwTerminate(); //���� �޸� ����
    exit(EXIT_SUCCESS); //���� ����
}