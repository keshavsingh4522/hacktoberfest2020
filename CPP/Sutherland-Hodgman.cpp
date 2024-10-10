#include <GL/freeglut.h>
#include <iostream>
#include <vector>

using namespace std;

// Define clipping window coordinates
float xMin, xMax, yMin, yMax;

// Function to compute intersection point with an edge
void computeIntersection(float x0, float y0, float x1, float y1, float& xIntersect, float& yIntersect, int edge) {
    float m = (y1 - y0) / (x1 - x0); // Slope of the line

    switch (edge) {
        case 0: // Left edge
            xIntersect = xMin;
            yIntersect = y0 + m * (xIntersect - x0);
            break;
        case 1: // Right edge
            xIntersect = xMax;
            yIntersect = y0 + m * (xIntersect - x0);
            break;
        case 2: // Top edge
            yIntersect = yMax;
            xIntersect = x0 + (yIntersect - y0) / m;
            break;
        case 3: // Bottom edge
            yIntersect = yMin;
            xIntersect = x0 + (yIntersect - y0) / m;
            break;
    }
}

// Function to clip a polygon using Sutherland-Hodgman algorithm
void sutherlandHodgmanClip(vector<float>& polyX, vector<float>& polyY) {
    vector<float> clippedX = polyX;
    vector<float> clippedY = polyY;

    vector<float> tempX, tempY;
    float x0, y0, x1, y1, xIntersect, yIntersect;

    // Clip against four edges: left, right, top, bottom
    for (int edge = 0; edge < 4; edge++) {
        int inputSize = clippedX.size();
        tempX.clear();
        tempY.clear();

        x0 = clippedX[inputSize - 1];
        y0 = clippedY[inputSize - 1];

        for (int j = 0; j < inputSize; j++) {
            x1 = clippedX[j];
            y1 = clippedY[j];

            bool inside0 = false, inside1 = false;

            switch (edge) {
                case 0: // Left
                    inside0 = (x0 >= xMin);
                    inside1 = (x1 >= xMin);
                    break;
                case 1: // Right
                    inside0 = (x0 <= xMax);
                    inside1 = (x1 <= xMax);
                    break;
                case 2: // Top
                    inside0 = (y0 <= yMax);
                    inside1 = (y1 <= yMax);
                    break;
                case 3: // Bottom
                    inside0 = (y0 >= yMin);
                    inside1 = (y1 >= yMin);
                    break;
            }

            if (inside1) {
                if (!inside0) { // Point 0 is outside, Point 1 is inside
                    computeIntersection(x0, y0, x1, y1, xIntersect, yIntersect, edge);
                    tempX.push_back(xIntersect);
                    tempY.push_back(yIntersect);
                }
                tempX.push_back(x1);
                tempY.push_back(y1);
            } else if (inside0) { // Point 0 is inside, Point 1 is outside
                computeIntersection(x0, y0, x1, y1, xIntersect, yIntersect, edge);
                tempX.push_back(xIntersect);
                tempY.push_back(yIntersect);
            }

            x0 = x1;
            y0 = y1;
        }

        clippedX = tempX;
        clippedY = tempY;
    }

    // Draw the clipped polygon
    if (!clippedX.empty()) {
        cout << "Polygon Accepted with vertices:" << endl;
        for (size_t i = 0; i < clippedX.size(); i++) {
            cout << "(" << clippedX[i] << ", " << clippedY[i] << ")" << endl;
        }

        glBegin(GL_POLYGON);
        for (size_t i = 0; i < clippedX.size(); i++) {
            glVertex2f(clippedX[i], clippedY[i]);
        }
        glEnd();
    } else {
        cout << "Polygon Rejected" << endl;
    }
}

// Display callback function for Sutherland-Hodgman
void displayPolygon() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the clipping window
    glBegin(GL_LINE_LOOP);
    glVertex2f(xMin, yMin);
    glVertex2f(xMax, yMin);
    glVertex2f(xMax, yMax);
    glVertex2f(xMin, yMax);
    glEnd();

    // Prompt user for polygon coordinates
    int numVertices;
    cout << "Enter the number of vertices in the polygon: ";
    cin >> numVertices;

    vector<float> polyX(numVertices);
    vector<float> polyY(numVertices);

    // Input polygon coordinates from the user
    for (int i = 0; i < numVertices; i++) {
        cout << "Enter coordinates for vertex " << i + 1 << " (x y): ";
        cin >> polyX[i] >> polyY[i];
    }

    // Perform clipping
    sutherlandHodgmanClip(polyX, polyY);

    glFlush(); // Ensure drawing is flushed
}

// Initialize OpenGL for Sutherland-Hodgman
void initPolygon() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
}

// Main function for Sutherland-Hodgman
int main(int argc, char** argv) {
    cout << "Enter clipping window coordinates (xmin, xmax, ymin, ymax): ";
    cin >> xMin >> xMax >> yMin >> yMax;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Siddharth Joshi");  // Set window title
    glViewport(0, 0, 500, 500);
    gluOrtho2D(xMin, xMax, yMin, yMax);  // Set coordinate system based on input

    initPolygon();
    glutDisplayFunc(displayPolygon);
    glutMainLoop();
    return 0;
}
