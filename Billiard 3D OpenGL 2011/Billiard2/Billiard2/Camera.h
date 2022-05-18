#pragma once
#include "Position.h"
#include "Size.h"
#include "Ball.h"
#include "QuadricPtr.h"

class Camera
{
public:
  using Angle = Position;
private:
  static constexpr float speed = 0.003f;

  QuadricPtr quadric;
  Position pos; //����������
  Size size;    //������ ������
  float force;  // ���� �����
  float scale;  // ����������� � ����
  float Aa, Bb, xi, yi, xj, yj;
  Angle angle; //���� ������
public:
  void setBall(const Ball&);
  void moveForward();
  void moveBackward();
  void moveLeft();
  void moveRight();
  void rotate(float angleX, float angleY);
  void resize(size_t width, size_t height);
  Angle viewAngle() const;
  void draw();
private:
  void move(int direction1, int direction2, float(*trig1)(float), float(*trig2)(float));
};
