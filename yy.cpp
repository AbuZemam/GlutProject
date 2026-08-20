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

void circle(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    float pi = 3.1416f;
    for (int i = 0; i < 200; i++) {
        float A = (i * 2.0f * pi) / 200.0f;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

// electric pillar er code eita (wire chara)
void ElectricPillar(float x, float baseY) {
    // main pillar/pole
    glColor3f(0.38f, 0.40f, 0.45f);
    drawRect(x - 0.6f, baseY, x + 0.6f, 30.0f);

    // 1st crossbar (uporer bar)
    drawRect(x - 5.5f, 26.5f, x + 5.5f, 28.0f);
    // 2nd crossbar (nicher bar)
    drawRect(x - 4.2f, 20.5f, x + 4.2f, 22.0f);

    // insulators (choto cap)
    glColor3f(0.82f, 0.85f, 0.90f);
    drawRect(x - 5.0f, 28.0f, x - 4.3f, 29.2f);
    drawRect(x + 4.3f, 28.0f, x + 5.0f, 29.2f);
    drawRect(x - 3.8f, 22.0f, x - 3.1f, 23.2f);
    drawRect(x + 3.1f, 22.0f, x + 3.8f, 23.2f);
}

// dustbin er code eita
void Dustbin(float x, float y) {
    // body
    glColor3f(0.20f, 0.60f, 0.35f);
    drawRect(x - 3.0f, y, x + 3.0f, y + 9.0f);

    // dhakna
    glColor3f(0.12f, 0.45f, 0.25f);
    drawRect(x - 3.5f, y + 9.0f, x + 3.5f, y + 10.5f);
}

// windmill er code eita
void WindmillDirect() {
    // pillar
    glColor3ub(230, 230, 230);
    glBegin(GL_POLYGON);
    glVertex2f(77.5f, -22.0f);
    glVertex2f(82.5f, -22.0f);
    glVertex2f(81.0f,  15.0f);
    glVertex2f(79.0f,  15.0f);
    glEnd();

    // pakha
    glColor3ub(245, 245, 245);

    // uporer pakha
    glBegin(GL_POLYGON);
    glVertex2f(79.0f, 15.0f);
    glVertex2f(77.5f, 32.0f);
    glVertex2f(82.5f, 32.0f);
    glVertex2f(81.0f, 15.0f);
    glEnd();

    // nicher pakha
    glBegin(GL_POLYGON);
    glVertex2f(81.0f,  15.0f);
    glVertex2f(82.5f,  -2.0f);
    glVertex2f(77.5f,  -2.0f);
    glVertex2f(79.0f,  15.0f);
    glEnd();

    // daner pakha
    glBegin(GL_POLYGON);
    glVertex2f(80.0f,  16.0f);
    glVertex2f(97.0f,  17.5f);
    glVertex2f(97.0f,  12.5f);
    glVertex2f(80.0f,  14.0f);
    glEnd();

    // bamer pakha
    glBegin(GL_POLYGON);
    glVertex2f(80.0f,  14.0f);
    glVertex2f(63.0f,  12.5f);
    glVertex2f(63.0f,  17.5f);
    glVertex2f(80.0f,  16.0f);
    glEnd();

    // majher circle
    circle(2.2f, 80.0f, 15.0f, 40, 40, 40);
}

// Gacher code eita
void TinyTree(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    glColor3f(0.10f, 0.08f, 0.05f);
    drawRect(-1.0f, 0.0f, 1.0f, 4.0f);

    glColor3ub(31, 71, 36);
    drawTriangle(-6.0f, 3.0f, 6.0f, 3.0f, 0.0f, 12.0f);
    drawTriangle(-5.0f, 9.0f, 5.0f, 9.0f, 0.0f, 18.0f);
    drawTriangle(-4.0f, 15.0f, 4.0f, 15.0f, 0.0f, 23.0f);

    glPopMatrix();
}

// Dromer code eita
void Drone(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    // body
    glColor3f(0.18f, 0.18f, 0.22f);
    drawRect(-3.0f, -1.4f, 3.0f, 1.4f);

    // Dron er hat
    glColor3f(0.25f, 0.25f, 0.28f);
    drawRect(-8.5f, -0.4f, 8.5f, 0.4f);

    // tran
    glColor3f(0.76f, 0.58f, 0.35f);
    drawRect(-1.8f, -3.8f, 1.8f, -1.4f);

    // line
    glColor3f(0.12f, 0.12f, 0.15f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2f(-8.5f, 0.4f);
    glVertex2f(-8.5f, 1.6f);
    glVertex2f(8.5f, 0.4f);
    glVertex2f(8.5f, 1.6f);
    glEnd();

    // pakha
    glColor3f(0.95f, 0.25f, 0.25f);
    drawRect(-12.5f, 1.6f, -4.5f, 2.0f);
    drawRect(4.5f, 1.6f, 12.5f, 2.0f);

    glPopMatrix();
}

// megh
void SingleCloud(float x, float y, float scale) {
    circle(0.6f * scale, x - 0.5f * scale, y, 255, 255, 255);
    circle(0.8f * scale, x, y + 0.3f * scale, 255, 255, 255);
    circle(0.6f * scale, x + 0.5f * scale, y, 255, 255, 255);
}

// EIkhane Sun megh er code ache
void drawSky() {
    // surjo
    circle(12.0f, 72.0f, 75.0f, 255, 215, 0);

    // megh
    SingleCloud(-65.0f, 78.0f, 11.0f);
    SingleCloud(-10.0f, 82.0f, 12.0f);
    SingleCloud(40.0f, 76.0f, 10.0f);
}

// background building 1
void drawBgBrickTower(float baseY) {
    glColor3f(0.48f, 0.28f, 0.24f);
    drawRect(-94.0f, baseY, -66.0f, 30.0f);
    glColor3f(0.38f, 0.20f, 0.18f);
    drawRect(-89.0f, 30.0f, -71.0f, 34.5f);
    glColor3f(0.82f, 0.76f, 0.70f);
    for (float wy = 5.0f; wy <= 26.0f; wy += 5.5f) {
        drawRect(-90.5f, wy, -87.0f, wy + 3.0f);
        drawRect(-85.5f, wy, -82.0f, wy + 3.0f);
        drawRect(-78.5f, wy, -75.0f, wy + 3.0f);
        drawRect(-73.5f, wy, -70.0f, wy + 3.0f);
    }
}

// background building 2
void Germents(float baseY) {
    glColor3f(0.42f, 0.50f, 0.58f);
    drawRect(-61.0f, baseY, -28.0f, 44.0f);
    glColor3f(0.30f, 0.38f, 0.45f);
    drawRect(-61.0f, 44.0f, -28.0f, 47.0f);
    for (float wy = 18.0f; wy <= 39.0f; wy += 7.0f) {
        glColor3f(0.68f, 0.82f, 0.92f);
        drawRect(-58.5f, wy, -30.5f, wy + 4.0f);
        glColor3f(0.35f, 0.45f, 0.52f);
        drawRect(-49.5f, wy, -48.5f, wy + 4.0f);
        drawRect(-40.5f, wy, -39.5f, wy + 4.0f);
    }
}

// background building 3
void triangleBuilding(float baseY) {
    glColor3f(0.35f, 0.48f, 0.55f);
    drawRect(-7.0f, baseY, 19.0f, 48.0f);
    glColor3f(0.26f, 0.38f, 0.45f);
    drawTriangle(-7.0f, 48.0f, 19.0f, 48.0f, 6.0f, 58.0f);
    glColor3f(0.75f, 0.88f, 0.96f);
    for (float wy = 24.0f; wy <= 42.0f; wy += 6.5f) {
        drawRect(-3.5f, wy, 0.5f, wy + 4.0f);
        drawRect(3.5f, wy, 7.5f, wy + 4.0f);
        drawRect(10.5f, wy, 14.5f, wy + 4.0f);
    }
}

// 1st building
void ShopBuilding(float baseY) {
    glColor3f(0.92f, 0.78f, 0.40f);
    drawRect(-100.0f, baseY, -74.0f, 8.0f);
    glColor3f(0.75f, 0.60f, 0.30f);
    drawRect(-100.0f, 8.0f, -74.0f, 10.5f);

    for (float wy = -24.0f; wy <= 0.0f; wy += 11.0f) {
        glColor3f(0.12f, 0.25f, 0.40f);
        drawRect(-97.0f, wy - 0.5f, -89.0f, wy + 6.5f);
        glColor3f(0.20f, 0.45f, 0.68f);
        drawRect(-96.5f, wy, -89.5f, wy + 6.0f);
        glColor3f(0.12f, 0.25f, 0.40f);
        drawRect(-93.3f, wy, -92.7f, wy + 6.0f);

        glColor3f(0.12f, 0.25f, 0.40f);
        drawRect(-85.0f, wy - 0.5f, -77.0f, wy + 6.5f);
        glColor3f(0.20f, 0.45f, 0.68f);
        drawRect(-84.5f, wy, -77.5f, wy + 6.0f);
        glColor3f(0.12f, 0.25f, 0.40f);
        drawRect(-81.3f, wy, -80.7f, wy + 6.0f);
    }

    glColor3f(0.25f, 0.15f, 0.08f);
    drawRect(-90.0f, baseY, -84.0f, -26.5f);
    glColor3f(0.45f, 0.25f, 0.15f);
    drawRect(-89.5f, baseY, -84.5f, -27.0f);
    glColor3f(0.78f, 0.88f, 0.95f);
    drawRect(-88.5f, -31.5f, -85.5f, -28.5f);
}

// 2nd building
void YellowBuilding(float baseY) {
    glColor3f(0.90f, 0.45f, 0.21f);
    drawRect(-74.0f, baseY, -48.0f, -9.0f);
    
    glColor3f(0.60f, 0.35f, 0.25f);
    drawRect(-74.0f, -9.0f, -48.0f, -6.5f);

    glColor3f(0.85f, 0.3f, 0.2f);
    drawRect(-70.0f, -24.0f, -52.0f, -19.5f);

    glColor3f(0.20f, 0.15f, 0.12f);
    drawRect(-68.5f, -17.5f, -53.5f, -11.0f);
    glColor3f(0.72f, 0.90f, 0.98f);
    drawRect(-68.0f, -17.0f, -54.0f, -11.5f);
    glColor3f(0.35f, 0.45f, 0.55f);
    drawRect(-61.3f, -17.0f, -60.7f, -11.5f);

    glColor3f(0.20f, 0.15f, 0.12f);
    drawRect(-64.5f, baseY, -56.5f, -26.5f);
    glColor3f(0.75f, 0.90f, 0.98f);
    drawRect(-64.0f, baseY, -57.0f, -27.0f);
    glColor3f(0.25f, 0.20f, 0.18f);
    drawRect(-60.8f, baseY, -60.2f, -27.0f);
}

// 3rd building
void RedBrickBuilding(float baseY) {
    glColor3f(0.78f, 0.38f, 0.32f);
    drawRect(-48.0f, baseY, -22.0f, 2.0f);
    glColor3f(0.58f, 0.26f, 0.22f);
    drawRect(-49.0f, 2.0f, -21.0f, 4.0f);

    for (float wy = -26.0f; wy <= -5.0f; wy += 9.5f) {
        glColor3f(0.85f, 0.94f, 1.0f);
        drawRect(-44.5f, wy, -39.5f, wy + 5.5f);
        glColor3f(0.65f, 0.25f, 0.20f);
        drawRect(-42.3f, wy, -41.7f, wy + 5.5f);
        drawRect(-44.5f, wy + 2.5f, -39.5f, wy + 3.0f);

        glColor3f(0.85f, 0.94f, 1.0f);
        drawRect(-30.5f, wy, -25.5f, wy + 5.5f);
        glColor3f(0.65f, 0.25f, 0.20f);
        drawRect(-28.3f, wy, -27.7f, wy + 5.5f);
        drawRect(-30.5f, wy + 2.5f, -25.5f, wy + 3.0f);
    }

    glColor3f(0.20f, 0.12f, 0.10f);
    drawRect(-38.2f, baseY, -31.8f, -26.0f);
    drawRect(-38.7f, -26.0f, -31.3f, -25.2f);
    glColor3f(0.35f, 0.20f, 0.15f);
    drawRect(-37.6f, baseY, -32.4f, -26.4f);
    glColor3f(0.25f, 0.14f, 0.10f);
    drawRect(-37.0f, -32.5f, -33.0f, -28.0f);
    drawRect(-37.0f, -38.5f, -33.0f, -34.0f);
}

// 4th building
void HQBuilding(float baseY) {
    glColor3f(0.60f, 0.68f, 0.75f);
    drawRect(-22.0f, baseY, 4.0f, 13.0f);
    glColor3f(0.45f, 0.50f, 0.55f);
    drawRect(-22.0f, 13.0f, 4.0f, 15.5f);

    for (float wy = -22.5f; wy <= 5.5f; wy += 9.5f) {
        glColor3f(0.40f, 0.48f, 0.55f);
        drawRect(-19.0f, wy - 0.4f, 1.0f, wy + 5.9f);
        glColor3f(0.72f, 0.88f, 0.98f);
        drawRect(-18.5f, wy, 0.5f, wy + 5.5f);
        glColor3f(0.45f, 0.55f, 0.65f);
        for (float px = -14.0f; px <= -2.0f; px += 4.5f) {
            drawRect(px - 0.3f, wy, px + 0.3f, wy + 5.5f);
        }
    }

    glColor3f(0.25f, 0.30f, 0.40f);
    drawRect(-12.0f, baseY, -6.0f, -25.5f);
    glColor3f(0.68f, 0.85f, 0.95f);
    drawRect(-11.5f, baseY, -6.5f, -26.0f);
    glColor3f(0.35f, 0.45f, 0.55f);
    drawRect(-9.3f, baseY, -8.7f, -26.0f);
}

// HG
void BlueTower(float baseY) {
    glColor3f(0.35f, 0.65f, 0.75f);
    drawRect(4.0f, baseY, 30.0f, 21.0f);
    glColor3f(0.25f, 0.50f, 0.60f);
    drawRect(4.0f, 21.0f, 30.0f, 24.0f);

    for (float wy = -24.0f; wy <= 12.0f; wy += 11.5f) {
        glColor3f(0.22f, 0.48f, 0.58f);
        drawRect(6.5f, wy - 0.5f, 14.5f, wy + 6.5f);
        glColor3f(0.85f, 0.95f, 1.0f);
        drawRect(7.0f, wy, 14.0f, wy + 6.0f);
        glColor3f(0.35f, 0.60f, 0.70f);
        drawRect(10.2f, wy, 10.8f, wy + 6.0f);

        glColor3f(0.22f, 0.48f, 0.58f);
        drawRect(19.5f, wy - 0.5f, 27.5f, wy + 6.5f);
        glColor3f(0.85f, 0.95f, 1.0f);
        drawRect(20.0f, wy, 27.0f, wy + 6.0f);
        glColor3f(0.35f, 0.60f, 0.70f);
        drawRect(23.2f, wy, 23.8f, wy + 6.0f);
    }

    // antena
    glColor3f(0.20f, 0.22f, 0.25f);
    drawRect(25.1f, 24.0f, 25.7f, 32.5f);
    circle(0.40f, 25.4f, 33.0f, 255, 30, 30);

    // dorja
    glColor3f(0.18f, 0.22f, 0.28f);
    drawRect(14.0f, baseY, 20.0f, -27.0f);
    glColor3f(0.80f, 0.92f, 0.98f);
    drawRect(14.5f, baseY, 19.5f, -27.5f);
    glColor3f(0.25f, 0.35f, 0.45f);
    drawRect(16.8f, baseY, 17.2f, -27.5f);
}

// park and dron zone
void parkArea(float baseY) {
    // ghas er part
    glColor3f(0.42f, 0.75f, 0.22f);
    drawRect(30.0f, baseY, 100.0f, -22.0f);

    // Dron er landing pad
    glColor3f(0.55f, 0.55f, 0.58f);
    drawRect(38.0f, -37.0f, 75.0f, -24.0f);

    // GACH ER
    TinyTree(94.0f, -22.0f);
    
    // DRON
    Drone(47.0f, -28.5f);
    Drone(66.0f, -28.5f);

    // dustbin
    Dustbin(80.0f, baseY);
}

// background layer
void drawBackgroundBuildings() {
    float baseY = -40.0f;
    drawBgBrickTower(baseY);
    Germents(baseY);
    triangleBuilding(baseY);

    // electric pillar 
    ElectricPillar(46.0f, -22.0f);
}

// foreground building layer
void drawForegroundBuildings() {
    float baseY = -40.0f;
    ShopBuilding(baseY);
    YellowBuilding(baseY);
    RedBrickBuilding(baseY);
    HQBuilding(baseY);
    BlueTower(baseY);
    parkArea(baseY);
    WindmillDirect();
}

// LAMPPOST
void drawLampPost(float x) {
    glColor3f(0.25f, 0.25f, 0.25f);
    drawRect(x - 0.4f, -40.0f, x + 0.4f, -20.5f);
    drawRect(x - 0.4f, -21.0f, x + 4.5f, -20.0f);
    circle(1.1f, x + 4.0f, -21.4f, 255, 240, 150);
}

// main ROad
void drawRoad() {
    // buildin er nicher part
    glColor3f(0.72f, 0.72f, 0.72f);
    drawRect(-100.0f, -45.0f, 100.0f, -40.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    for (float x = -100.0f; x <= 100.0f; x += 13.0f) {
        glVertex2f(x, -45.0f);
        glVertex2f(x, -40.0f);
    }
    glEnd();

    // main rasta
    glColor3f(0.18f, 0.18f, 0.20f);
    drawRect(-100.0f, -100.0f, 100.0f, -45.0f);

    // rasta er majh er line
    glColor3f(1.0f, 1.0f, 1.0f);
    for (float x = -80.0f; x <= 85.0f; x += 38.0f) {
        drawRect(x, -73.0f, x + 15.0f, -71.0f);
    }
}

// gari er code eita
void Car(float x, float y, float r, float g, float b) {
    // body
    glColor3f(r, g, b);
    drawRect(x - 12.0f, y - 2.0f, x + 12.0f, y + 4.0f);
    drawRect(x - 7.0f,  y + 4.0f, x + 6.0f,  y + 10.0f);

    // janala
    glColor3f(0.75f, 0.90f, 1.0f);
    drawRect(x - 6.0f, y + 5.0f, x - 1.0f, y + 9.0f);
    drawRect(x + 1.0f, y + 5.0f, x + 5.0f, y + 9.0f);

    // headlight
    circle(1.0f, x + 12.0f, y + 1.5f, 255, 230, 80);

    // caka
    circle(2.5f, x - 7.0f, y - 2.0f, 20, 20, 20);
    circle(2.5f, x + 7.0f, y - 2.0f, 20, 20, 20);
}

// bus er code eikhae ache
void drawBus(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);

    // body
    glColor3f(0.0f, 0.75f, 0.35f);
    drawRect(-22.0f, -2.0f, 22.0f, 15.0f);

    // janala
    glColor3f(0.75f, 0.90f, 1.0f);
    for (float wx = -18.0f; wx <= 3.0f; wx += 7.0f) {
        drawRect(wx, 6.0f, wx + 5.0f, 12.0f);
    }

    // shamner glass
    drawRect(7.6f, 4.4f, 22.0f, 13.2f);

    // batti
    circle(1.2f, 21.6f, 1.6f, 255, 235, 80);

    // caka
    circle(3.2f, -13.0f, -2.0f, 20, 20, 20);
    circle(3.2f,  13.0f, -2.0f, 20, 20, 20);

    glPopMatrix();
}

void display() {
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawSky();
    drawBackgroundBuildings();
    drawForegroundBuildings();
    drawLampPost(-75.0f);
    drawLampPost(31.0f);
    drawRoad();

    // gari
    drawBus(-50.0f, -59.0f);
    Car(14.0f, -58.0f, 0.95f, 0.12f, 0.12f);
    Car(-22.0f, -86.0f, 0.05f, 0.48f, 0.95f);
    Car(55.0f, -86.0f, 0.98f, 0.78f, 0.05f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1100, 750);
    glutCreateWindow("City Scene OpenGL");

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}