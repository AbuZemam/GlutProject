#include <GLUT/glut.h>
#include <math.h>


void drawRect(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawCircle(float radius, float xc, float yc) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = (i * 2.0f * 3.14159265f) / 100.0f;
        glVertex2f(xc + radius * cosf(angle), yc + radius * sinf(angle));
    }
    glEnd();
}




// main ROad
void drawRoad() {
    // buildin er nicher part
    glColor3f(0.72f, 0.72f, 0.72f);
    drawRect(-11.5f, -1.35f, 11.5f, -1.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    for (float x = -11.5f; x <= 11.5f; x += 1.5f) {
        glVertex2f(x, -1.35f);
        glVertex2f(x, -1.0f);
    }
    glEnd();

    //main rasta
    glColor3f(0.18f, 0.18f, 0.20f);
    drawRect(-11.5f, -6.0f, 11.5f, -1.35f);

//rasta er majh er line
    glColor3f(1.0f, 1.0f, 1.0f);
    for (float x = -9.0f; x <= 9.5f; x += 4.5f) {
        drawRect(x, -3.75f, x + 1.8f, -3.60f);
    }
}




// Gacher code eita
void drawTinyTree(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    
    glColor3f(0.10f, 0.08f, 0.05f);
    drawRect(-4.0f, 0.0f, 4.0f, 15.0f);

   
    glColor3ub(31, 71, 36);
    drawTriangle(-25.0f, 10.0f, 25.0f, 10.0f, 0.0f, 45.0f);
    drawTriangle(-20.0f, 30.0f, 20.0f, 30.0f, 0.0f, 65.0f);
    drawTriangle(-15.0f, 50.0f, 15.0f, 50.0f, 0.0f, 80.0f);

    glPopMatrix();
}

// Dromer code eita
void drawDrone(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

        // body
    glColor3f(0.18f, 0.18f, 0.22f);
    drawRect(-0.30f, -0.14f, 0.30f, 0.14f);

    //Dron er hat
    glColor3f(0.25f, 0.25f, 0.28f);
    drawRect(-0.85f, -0.04f, 0.85f, 0.04f);



    // tran
    glColor3f(0.76f, 0.58f, 0.35f);
    drawRect(-0.18f, -0.38f, 0.18f, -0.14f);


    // line
    glColor3f(0.12f, 0.12f, 0.15f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2f(-0.85f, 0.04f);
    glVertex2f(-0.85f, 0.16f);
    glVertex2f(0.85f, 0.04f);
    glVertex2f(0.85f, 0.16f);
    glEnd();

    // pakha
    glColor3f(0.95f, 0.25f, 0.25f);
    drawRect(-1.25f, 0.16f, -0.45f, 0.20f);
    drawRect(0.45f, 0.16f, 1.25f, 0.20f);

    glPopMatrix();
}

//megh
void drawSingleCloud(float x, float y, float scale) {
    glColor3ub(255, 255, 255);
    drawCircle(0.6f * scale, x - 0.5f * scale, y);
    drawCircle(0.8f * scale, x, y + 0.3f * scale);
    drawCircle(0.6f * scale, x + 0.5f * scale, y);
}

// EIkhane Sun megh er code ache
void drawSky() {
    // surjo
    glColor3ub(255, 215, 0);
    drawCircle(1.2f, 9.0f, 8.8f);

    // megh
    drawSingleCloud(-7.5f, 8.5f, 1.2f);
    drawSingleCloud(-1.0f, 8.8f, 1.3f);
    drawSingleCloud(5.0f, 8.2f, 1.1f);
}


void drawBuildings() {
    float baseY = -1.0f;

    // 1st building
    glColor3f(0.76f, 0.45f, 0.35f);
    drawRect(-11.5f, baseY, -8.5f, 2.5f);
    glColor3f(0.60f, 0.35f, 0.25f);
    drawRect(-11.5f, 2.5f, -8.5f, 2.8f);
    glColor3f(0.3f, 0.2f, 0.15f);
    drawRect(-10.3f, baseY, -9.5f, 0.5f);
    glColor3f(0.85f, 0.3f, 0.2f);
    drawRect(-11.0f, 0.8f, -9.0f, 1.3f);
    glColor3f(0.7f, 0.9f, 1.0f);
    drawRect(-10.8f, 1.6f, -9.2f, 2.2f);

    // 2nd building
    glColor3f(0.92f, 0.78f, 0.40f);
    drawRect(-8.5f, baseY, -5.5f, 4.5f);
    glColor3f(0.75f, 0.60f, 0.30f);
    drawRect(-8.5f, 4.5f, -5.5f, 4.8f);
    glColor3f(0.35f, 0.2f, 0.1f);
    drawRect(-7.3f, baseY, -6.7f, 0.4f);
    glColor3f(0.2f, 0.4f, 0.6f);
    for (float wy = 0.8f; wy <= 3.6f; wy += 1.3f) {
        drawRect(-8.1f, wy, -7.3f, wy + 0.7f);
        drawRect(-6.7f, wy, -5.9f, wy + 0.7f);
    }

    // 3rd building
    glColor3f(0.78f, 0.38f, 0.32f);
    drawRect(-5.5f, baseY, -2.5f, 3.8f);
    glColor3f(0.58f, 0.26f, 0.22f);
    drawRect(-5.6f, 3.8f, -2.4f, 4.05f);
    glColor3f(0.25f, 0.15f, 0.12f);
    drawRect(-4.3f, baseY, -3.7f, 0.45f);
    glColor3f(0.88f, 0.95f, 1.0f);
    for (float wy = 0.6f; wy <= 3.0f; wy += 1.1f) {
        drawRect(-5.1f, wy, -4.5f, wy + 0.65f);
        drawRect(-3.5f, wy, -2.9f, wy + 0.65f);
    }

    // 4th building
    glColor3f(0.60f, 0.68f, 0.75f);
    drawRect(-2.5f, baseY, 0.5f, 5.0f);
    glColor3f(0.45f, 0.50f, 0.55f);
    drawRect(-2.5f, 5.0f, 0.5f, 5.3f);
    glColor3f(0.75f, 0.90f, 0.98f);
    for (float wy = 1.0f; wy <= 4.2f; wy += 1.1f) {
        drawRect(-2.1f, wy, 0.1f, wy + 0.65f);
    }
    glColor3f(0.25f, 0.30f, 0.40f);
    drawRect(-1.3f, baseY, -0.7f, 0.6f);

    // HG
    glColor3f(0.35f, 0.65f, 0.75f);
    drawRect(0.5f, baseY, 3.5f, 6.0f);
    glColor3f(0.25f, 0.50f, 0.60f);
    drawRect(0.5f, 6.0f, 3.5f, 6.3f);
    glColor3f(0.2f, 0.25f, 0.35f);
    drawRect(1.7f, baseY, 2.3f, 0.5f);
    glColor3f(0.85f, 0.95f, 1.0f);
    for (float wy = 0.8f; wy <= 5.0f; wy += 1.3f) {
        drawRect(0.85f, wy, 1.65f, wy + 0.7f);
        drawRect(2.35f, wy, 3.15f, wy + 0.7f);
    }
    // antena
    glColor3f(0.2f, 0.2f, 0.2f);
    drawRect(1.9f, 6.3f, 2.1f, 7.2f);
    glColor3ub(255, 0, 0);
    drawCircle(0.15f, 2.0f, 7.25f);

    // ghas er part
    glColor3f(0.42f, 0.75f, 0.22f);
    drawRect(3.5f, baseY, 11.5f, 1.0f);

    // Dron er landing pad
    glColor3f(0.55f, 0.55f, 0.58f);
    drawRect(4.6f, -0.7f, 8.4f, 0.7f);

    // GACH ER
    drawTinyTree(9.8f, baseY, 0.035f);

    // DRON
    drawDrone(5.4f, 0.20f, 0.70f);
    drawDrone(7.7f, 0.20f, 0.70f);
}

// LAMPPOST
void drawLampPost(float x) {
    glColor3f(0.25f, 0.25f, 0.25f);
    drawRect(x - 0.05f, -1.0f, x + 0.05f, 1.2f);
    drawRect(x - 0.05f, 1.15f, x + 0.5f, 1.25f);
    glColor3ub(255, 240, 150);
    drawCircle(0.12f, x + 0.45f, 1.1f);
}


// gari er code eita
void drawCar(float x, float y, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(1.2f, 1.2f, 1.0f);

    glColor3f(r, g, b);
    drawRect(-0.7f, -0.1f, 0.7f, 0.25f);
    drawRect(-0.4f, 0.25f, 0.35f, 0.55f);

    glColor3f(0.85f, 0.95f, 1.0f);
    drawRect(-0.35f, 0.28f, -0.05f, 0.50f);
    drawRect(0.05f, 0.28f, 0.30f, 0.50f);

    glColor3ub(255, 230, 100);
    drawCircle(0.05f, 0.68f, 0.08f);

    // caka
    glColor3ub(20, 20, 20);
    drawCircle(0.14f, -0.4f, -0.1f);
    drawCircle(0.14f, 0.4f, -0.1f);

    glPopMatrix();
}

// bus er code eikhae ache
void drawBus(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(1.2f, 1.2f, 1.0f);

    glColor3f(0.15f, 0.65f, 0.35f);
    drawRect(-1.1f, -0.1f, 1.1f, 0.75f);

    glColor3f(0.85f, 0.95f, 1.0f);
    for (float wx = -0.9f; wx <= 0.6f; wx += 0.42f) {
        drawRect(wx, 0.32f, wx + 0.30f, 0.62f);
    }

    glColor3ub(255, 240, 120);
    drawCircle(0.06f, 1.08f, 0.12f);

    // caka
    glColor3ub(20, 20, 20);
    drawCircle(0.16f, -0.65f, -0.1f);
    drawCircle(0.16f, 0.65f, -0.1f);

    glPopMatrix();
}

void display() {
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();
    drawBuildings();
    drawLampPost(-8.6f);
    drawLampPost(3.6f);
    drawRoad();

    // gari
    drawBus(-6.0f, -2.5f);
    drawCar(0.5f, -2.5f, 0.85f, 0.2f, 0.2f);
    drawCar(-2.0f, -4.8f, 0.2f, 0.45f, 0.88f);
    drawCar(6.0f, -4.8f, 0.95f, 0.8f, 0.2f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1100, 750);
    glutCreateWindow("City Scene OpenGL");

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-11.5, 11.5, -6.0, 11.0);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}