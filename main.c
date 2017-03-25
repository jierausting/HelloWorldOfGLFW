#include<GLFW/glfw3.h>

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

//���ô���ص�
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
//���ù���ESC���Ļص�
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

    /* ��ʼ��GLFW�� */
    if (!glfwInit())
        exit(EXIT_FAILURE);

    /*�������ں������� */
    window = glfwCreateWindow(640, 480, "Hello Magic", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    /* ������ǰ������*/
    glfwMakeContextCurrent(window);

    /*ѭ����Բ�Ĳ���*/
    int i;

    /* ��ѭ�� */
    while (!glfwWindowShouldClose(window))
    {
        /* ��ʼ��Ⱦ�׶� */
        float ratio;
        int width,height;

        /* ��ȡ����֡�Ĵ�С*/
        glfwGetFramebufferSize(window,&width,&height);
        ratio = width/(float) height;

        /*�����ӿڲ���֮ǰ����ɫ�������*/
        glViewport(0,0,width,height);
        glClear(GL_COLOR_BUFFER_BIT);

        /*���þ���ģʽΪͶ��ģʽ�������Ӿ���*/
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glOrtho(-ratio*2,ratio*2,-2.f,2.f,2.f,-2.f);

        /*  ����Ϊ����ģʽ      */
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        /*���������β������ɫ*/
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

        /*��Բ*/

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



        /*����������*/
        glfwSwapBuffers(window);

        /*�����¼�*/
        glfwPollEvents();
    }

    /*�رմ��ڲ�ֹͣʹ��GLFW�Ŀ�*/
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

