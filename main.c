#include<GLFW/glfw3.h>

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

//设置错误回调
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
//设置关于ESC键的回调
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
const GLfloat R = 1.f;
const GLfloat Pi = 3.1415926536f;
const int n = 3600;
const int m = 36;
int main(void)
{
    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);

    /* 初始化GLFW库 */
    if (!glfwInit())
        exit(EXIT_FAILURE);

    /*创建窗口和上下文 */
    window = glfwCreateWindow(640, 480, "Hello Magic", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    /* 创建当前上下文*/
    glfwMakeContextCurrent(window);

    /*循环画圆的参数*/
    int i;

    /* 主循环 */
    while (!glfwWindowShouldClose(window))
    {
        /* 开始渲染阶段 */
        float ratio;
        int width,height;

        /* 获取缓存帧的大小*/
        glfwGetFramebufferSize(window,&width,&height);
        ratio = width/(float) height;

        /*创建视口并将之前的颜色缓存清除*/
        glViewport(0,0,width,height);
        glClear(GL_COLOR_BUFFER_BIT);

        /*设置矩阵模式为投射模式并设置视景体*/
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-ratio*2,ratio*2,-2.f,2.f,2.f,-2.f);

        /*  设置为空心模式      */
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        /*定义三角形并填充颜色*/
        glBegin(GL_TRIANGLES);
        glColor3f(255.f/255.f,0.f/255.f,0.f/255.f);
        glVertex3f(0.866f,-0.5f,0.f);
        glColor3f(255.f/255.f,0.f/255.f,0.f/255.f);
        glVertex3f(-0.866f,-0.5f,0.f);
        glColor3f(255.f/255.f,0.f/255.f,0.f/255.f);
        glVertex3f(0.f,1.f,0.f);
        glColor3f(255.f/255.f,0.f/255.f,0.f/255.f);
        glVertex3f(0.866f,0.5f,0.f);
        glColor3f(255.f/255.f,0.f/255.f,0.f/255.f);
        glVertex3f(-0.866f,0.5f,0.f);
        glColor3f(255.f/255.f,0.f/255.f,0.f/255.f);
        glVertex3f(0.f,-1.f,0.f);
        glEnd();

        /*画圆*/

        glBegin(GL_POINTS);
        glColor3f(255.f/255.f,0.f/255.f,0.f/255.f);
        for (i= 0;i<n;i++){
            glVertex3f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i),0.f);
        }
        glEnd();

        glBegin(GL_POINTS);
        glColor3f(255.f/255.f,0.f/255.f,0.f/255.f);
        for (i= 0;i<n;i++){
            glVertex3f(R*1.1*cos(2*Pi/n*i), R*1.1*sin(2*Pi/n*i),0.f);
        }
        glEnd();

        glBegin(GL_POINTS);
        glColor3f(255.f/255.f,0.f/255.f,0.f/255.f);
        for (i= 0;i<m;i++){
            glVertex3f(R*1.05*cos(2*Pi/m*i), R*1.05*sin(2*Pi/m*i),0.f);
        }
        glEnd();




//        glBegin(GL_LINES);
//        glColor3f(1.f,1.f,1.f);
//        glVertex3f(-0.6f,0.6f,0.f);
//        glVertex3f(0.6f,0.6f,0.f);
//        glVertex3f(-0.6f,-0.6f,0.f);
//        glVertex3f(0.6f,-0.6f,0.f);
//        glEnd();
//
//        glBegin(GL_QUADS);
//        glColor3f(1.f,1.f,1.f);
//        glVertex3f(0.9f,0.8f,0.f);
//        glVertex3f(0.9f,0.6f,0.f);
//        glVertex3f(0.7f,0.6f,0.f);
//        glVertex3f(0.7f,0.8f,0.f);
//
//        glEnd();



        /*交换缓存区*/
        glfwSwapBuffers(window);

        /*处理事件*/
        glfwPollEvents();
    }

    /*关闭窗口并停止使用GLFW的库*/
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

