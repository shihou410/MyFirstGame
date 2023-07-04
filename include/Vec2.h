#pragma once
#include <cmath>

class Vec2 {

public:
  float x, y;

  Vec2();
  Vec2(float x, float y);

  /** 向量加法*/
  Vec2 operator+(const Vec2 &vec2);

  /** 向量减法*/
  Vec2 operator-(const Vec2 &vec2);

  /** 向量数乘*/
  Vec2 operator*(float num);

  /** 向量点乘*/
  float operator*(const Vec2 &vec2);

  /** 向量模长*/
  float length();

  // 向量归一化
  Vec2 normalize();
};
