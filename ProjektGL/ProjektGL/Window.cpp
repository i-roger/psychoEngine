// Quadrado.c - Isabel H. Manssour
// Um programa OpenGL simples que desenha um 
// quadrado em  uma janela GLUT.
// Este código está baseado no GLRect.c, exemplo 
// disponível no livro "OpenGL SuperBible", 
// 2nd Edition, de Richard S. e Wright Jr.

#include <windows.h>
#include <gl/glut.h>

GLint tx, ty, angulo;
GLfloat ex, ey;
// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(tx, ty, 0);
    glScalef(ex, ey, 1);
    glRotatef(angulo, 0, 0, 1);

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Especifica que a cor corrente é vermelha
    //         R     G     B
    glColor3f(1.0f, 0.0f, 0.0f);

    glLineWidth(3);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(50, 100);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2i(100,150);
    glColor3f(0.2f, 0.0f, 1.0f);
    glVertex2i(150,100);
    glEnd();

    // Desenha 2linhas preenchido com a cor corrente
    glBegin(GL_LINE_LOOP);
    glVertex2i(50, 1);
    glVertex2i(50, 99);
    glVertex2i(150, 99);
    glVertex2i(150, 1);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(0,540);
    glVertex2i(0, -540);
    glVertex2i(540, 0);
    glVertex2i(-540,0);
    glEnd();

    // Executa os comandos OpenGL
    glFlush();
}


/* - TECLAS PARA MOVIMENTAÇÃO - */
void TeclasEspeciais(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_PAGE_UP:
        ex++;
        break;
    case GLUT_KEY_PAGE_DOWN:
        ex--;
        break;
    case GLUT_KEY_HOME:
        angulo++;
        break;
    case GLUT_KEY_END:
        angulo--;
        break;
    case GLUT_KEY_UP:
        ty++;
        break;
    case GLUT_KEY_DOWN:
        ty--;
        break;
    case GLUT_KEY_LEFT:
        tx--;
        break;
    case GLUT_KEY_RIGHT:
        tx++;
        break;
    }
    glutPostRedisplay();
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
    tx = 0;
    ty = 0;
    angulo = 0;
    ex = 1;
    ey = 1;

    // Define a cor de fundo da janela de visualização como preta
    //            R     G     B     A
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if (h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-250.0f, 250.0f, -250.0f, 250.0f);

    // Estabelece a janela de seleção (left, right, bottom, top)
    //if (w <= h)
    //    gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h / w);
    //else
    //    gluOrtho2D(0.0f, 250.0f * w / h, 0.0f, 250.0f);
}

// Programa Principal 
int main(void)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(768, 540);
    glutInitWindowPosition(600, 350);
    glutCreateWindow("PsychoGlut");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutSpecialFunc(TeclasEspeciais);
    glutMainLoop();
}