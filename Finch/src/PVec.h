#pragma once

class PVec {

public:

	float x = 0;
	float y = 0;
	float z = 0;

public:

	PVec(float x_, float y_);
	PVec(float x_, float y_, float z_);

	PVec Copy();
	static PVec Copy(PVec vec);

	float Mag();
	float MagSq();

	void PrintVals();
	static void PrintVals(PVec vec);

	void Set(float x_, float y_, float z_);
	void Set(float x_, float y_);

	void Add(PVec vec);
	void Add(float x_, float y_, float z_);
	static PVec Add(PVec vec1, PVec vec2);

	void Subtract(PVec vec);
	void Subtract(float x_, float y_, float z_);
	static PVec Subtract(PVec vec1, PVec vec2);

	void Mult(float n);
	static PVec Mult(PVec vec, float n);

	void Div(float n);
	static PVec Div(PVec vec, float n);

	float Dist(PVec vec);
	static float Dist(PVec vec1, PVec vec2);

	float Dot(PVec vec);
	static float Dot(PVec vec1, PVec vec2);

	PVec Cross(PVec vec);
	static PVec Cross(PVec vec1, PVec vec2);

	float AngleBetween(PVec vec2);
	static float AngleBetween(PVec vec1, PVec vec2);

	void Normalize();
	static PVec Normalize(PVec vec);

	void SetMag(float mag);
	static PVec(PVec vec, float mag);

	void Limit(flot magLimit);
	static PVec Limit(PVec vec, float magLimit);

	float* ToArray();
	static float* ToArray(PVec vec);
};
