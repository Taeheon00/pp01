#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib,"OpenGL32.lib")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr); //에러 출력 stdio사용
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) //esc키가 눌렸을때 참
        glfwSetWindowShouldClose(window, GL_TRUE); //창을 닫는다
}
int main(void)
{
    GLFWwindow* window; //window객채 생성
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) //glfw를 초기화 하여, Window 생성을 할 수 있는 상태로 설정해준다.
        exit(EXIT_FAILURE); //비정상 종료
    window = glfwCreateWindow(800, 480, "Simple example", NULL, NULL); //glfw 윈도우창 생성
    if (!window)
    {
        glfwTerminate(); //사용된 메모리 삭제
        exit(EXIT_FAILURE); //비정상 종료
    }
    glfwMakeContextCurrent(window); //Double Buffer로 사용할 Window를 등록하는 함수이며, 등록되면 Thread로 설정되어 사용된다.(GPU는 이중작업X 내가 지금 GPU를 점유한다고 선언하는것)
    glfwSetKeyCallback(window, key_callback); //키보드 이벤트 반응 함수

    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height); //프레임 버퍼 사이즈 지정    
    ratio = width / (float)height;

    while (!glfwWindowShouldClose(window)) //윈도우창이 종료됬는지 확인
    {
        glClearColor(1, 1, 1, 0); //배경색
        glClear(GL_COLOR_BUFFER_BIT); //색상버퍼 지움
        glColor3f(0.81, 1, 0.89); // 내부 도형색
        glBegin(GL_TRIANGLES); //삼각형을 그려라
        glVertex3f(-0.75, -0.6,0);
        glVertex3f(-0.9, -0.9,0);
        glVertex3f(-0.6, -0.9,0);
        glEnd();

        glLoadIdentity();

        glTranslatef(-0.5, 0, 0);
        glScalef(0.5, 0.5, 0.5);

        glfwSwapBuffers(window);
        glfwPollEvents(); //현재 Frame의 입력 및 출력 이벤트를 모두 처리 poll=게속확인하는작업
    }
    glfwDestroyWindow(window); //윈도우창 닫기
    glfwTerminate(); //사용된 메모리 삭제
    exit(EXIT_SUCCESS); //정상 종료
}