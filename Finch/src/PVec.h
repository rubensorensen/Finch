#pragma once

class PVec {

public:

	float x = 0;
	float y = 0;
	float z = 0;

public:

	PVec();
	PVec(float x, float y);
	PVec(float x, float y, float z);

	PVec Copy() const;
	static PVec Copy(PVec vec);

	float Mag() const;
	float MagSq() const;

	void PrintVals() const;
	static void PrintVals(PVec vec);

	void Set(float x, float y, float z);
	void Set(float x, float y);

	static PVec Random2D();
	static PVec Random3D();

	void Add(PVec vec);
	void Add(float x, float y, float z);
	static PVec Add(PVec vec1, PVec vec2);

	void Sub(PVec vec);
	void Sub(float x, float y, float z);
	static PVec Sub(PVec vec1, PVec vec2);

	void Mult(float n);
	static PVec Mult(PVec vec, float n);

	void Div(float n);
	static PVec Div(PVec vec, float n);

	float Dist(PVec vec) const;
	static float Dist(PVec vec1, PVec vec2);

	float Dot(PVec vec) const;
	static float Dot(PVec vec1, PVec vec2);

	PVec Cross(PVec vec) const;
	static PVec Cross(PVec vec1, PVec vec2);

	float AngleBetween(PVec vec) const;
	static float AngleBetween(PVec vec1, PVec vec2);

	void Normalize();
	static PVec Normalize(PVec vec);

	void SetMag(float mag);
	static PVec SetMag(PVec vec, float mag);

	void Limit(float magLimit);
	static PVec Limit(PVec vec, float magLimit);

	float* ToArray() const;
	static float* ToArray(PVec vec);
};
