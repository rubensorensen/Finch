#pragma once

class PVec {

private:

	float x = 0;
	float y = 0;
	float z = 0;

public:

	PVec(float x_, float y_);
	PVec(float x_, float y_, float z_);
	float Mag();
	float MagSq();
	void PrintVals();
	static void PrintVals(PVec vec);
	void Set(float x_, float y_, float z_);
	void Set(float x_, float y_);
	PVec Copy();
	void Mult(float n);
	void Div(float n);
	float Dist(PVec vec);
	float Dot(PVec vec);
	static float Dot(PVec vec1, PVec vec2);
	float AngleBetween(PVec vec2);
	PVec Cross(PVec vec);
	static PVec Cross(PVec vec1, PVec vec2);
	void Normalize();
	float* ToArray();
};
