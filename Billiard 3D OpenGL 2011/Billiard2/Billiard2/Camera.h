#pragma once
#include "Vector4.h"
#include "Size.h"
#include "Ball.h"
#include "Light.h"
#include "QuadricPtr.h"

class Camera
{
private:
  static constexpr float speed = 0.003f;

  Position pos; //����������
  Angle angle;  //���� ������
  float aspect; // ��� �����������
public:
  void setBall(const Ball&);
  void moveForward();
  void moveBackward();
  void moveLeft();
  void moveRight();
  void rotate(float angleX, float angleY);
  Angle viewAngle() const;
  void draw() const;
private:
  void move(int direction1, int direction2, float(*trig1)(float), float(*trig2)(float));
};
