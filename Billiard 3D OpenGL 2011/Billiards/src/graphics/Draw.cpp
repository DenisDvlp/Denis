#include "graphics/Draw.hpp"
#include <gl/gl.h>
#include <gl/glu.h>

namespace gl {

namespace material {

void reflection(float intensity, float sharpness) {
    const float color[] = {intensity, intensity, intensity, 1.0f};
    glMaterialfv(GL_FRONT, GL_SPECULAR, color);
    const float shininess = 128.0f * sharpness;
    glMaterialfv(GL_FRONT, GL_SHININESS, &shininess);
}

void glow(float intensity) {
    const float color[] = {intensity, intensity, intensity, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color);
}

void diffusion(float intensity) {
    const float color[] = {intensity, intensity, intensity, 1.0f};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
}

void ambient(float intensity) {
    const float color[] = {intensity, intensity, intensity, 1.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, color);
}

} // namespace material

namespace light {

void turn(int id, bool on) { on ? glEnable(id) : glDisable(id); }

void ambient(int id, float intensity) {
    const float color[] = {intensity, intensity, intensity, 1.0f};
    glLightfv(id, GL_AMBIENT, color);
}

void diffusion(int id, float intensity) {
    const float color[] = {intensity, intensity, intensity, 1.0f};
    glLightfv(id, GL_DIFFUSE, color);
}

void reflection(int id, float intensity) {
    const float color[] = {intensity, intensity, intensity, 1.0f};
    glLightfv(id, GL_SPECULAR, color);
}

void spotAngle(int id, float angle) { glLightf(id, GL_SPOT_CUTOFF, angle); }

void direction(int id, const float* xyz, bool isSpot) {
    if (isSpot) {
        static constexpr float xyzs[] = {0, 0, 0, 1.0f};
        glLightfv(id, GL_POSITION, xyzs);
        glLightfv(id, GL_SPOT_DIRECTION, xyz);
    } else {
        glLightfv(id, GL_POSITION, xyz);
    }
}

} // namespace light

namespace transform {

void position(const float* xyz) { glTranslatef(xyz[0], xyz[1], xyz[2]); }

void position(float x, float y, float z) { glTranslatef(x, y, z); }

void rotation(const float* xyz) {
    glRotatef(xyz[0], 1, 0, 0);
    glRotatef(xyz[1], 0, 1, 0);
    glRotatef(xyz[2], 0, 0, 1);
}

void rotationX(const float angle) { glRotatef(angle, 1, 0, 0); }

void rotationY(const float angle) { glRotatef(angle, 0, 1, 0); }

void rotationZ(const float angle) { glRotatef(angle, 0, 0, 1); }

} // namespace transform

namespace guard {

MaterialGuard::MaterialGuard() { glPushAttrib(GL_LIGHTING_BIT); }

MaterialGuard::~MaterialGuard() { glPopAttrib(); }

MatrixGuard::MatrixGuard() { glPushMatrix(); }

MatrixGuard::~MatrixGuard() { glPopMatrix(); }

} // namespace guard

} // namespace gl