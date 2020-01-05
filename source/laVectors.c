/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laVectors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:00:50 by vrichese          #+#    #+#             */
/*   Updated: 2019/11/28 20:28:06 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LLFC.h"

/*
** Initialization vector -----------------------------------------------------------
*/

vec2		laInit2DVector(vec2 *pSourceVector, float x, float y, float *pInitArray)
{
	vec2	newVector;

	if (!pInitArray)
	{
		newVector.data[LA_X] = x;
		newVector.data[LA_Y] = y;
	}
	else
		for (int i = 0; i < LA_2D; ++i)
			newVector.data[i] = pInitArray[i];
	if (pSourceVector)
	{
		*pSourceVector = newVector;
		return (*pSourceVector);
	}
	return (newVector);
}

vec3		laInit3DVector(vec3 *pSourceVector, float x, float y, float z, float *pInitArray)
{
	vec3	newVector;

	if (!pInitArray)
	{
		newVector.data[LA_X] = x;
		newVector.data[LA_Y] = y;
		newVector.data[LA_Z] = z;
	}
	else
		for (int i = 0; i < LA_3D; ++i)
			newVector.data[i] = pInitArray[i];
	if (pSourceVector)
	{
		*pSourceVector = newVector;
		return (*pSourceVector);
	}
	return (newVector);
}

vec4		laInit4DVector(vec4 *pSourceVector, float x, float y, float z, float w, float *pInitArray)
{
	vec4	newVector;

	if (!pInitArray)
	{
		newVector.data[LA_X] = x;
		newVector.data[LA_Y] = y;
		newVector.data[LA_Z] = z;
		newVector.data[LA_W] = w;
	}
	else
		for (int i = 0; i < LA_4D; ++i)
			newVector.data[i] = pInitArray[i];
	if (pSourceVector)
	{
		*pSourceVector = newVector;
		return (*pSourceVector);
	}
	return (newVector);
}

/*
** Copy vectors -----------------------------------------------------------------------------------
*/

vec2		laCopy2DVector(vec2 *pSourceVector, vec2 *pResultVector)
{
	vec2	newVector;

	if (!pSourceVector)
		return (newVector);
	for (int i = 0; i < LA_2D; ++i)
		newVector.data[i] = pSourceVector->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec3		laCopy3DVector(vec3 *pSourceVector, vec3 *pResultVector)
{
	vec3	newVector;

	if (!pSourceVector)
		return (newVector);
	for (int i = 0; i < LA_3D; ++i)
		newVector.data[i] = pSourceVector->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec4		laCopy4DVector(vec4 *pSourceVector, vec4 *pResultVector)
{
	vec4	newVector;

	if (!pSourceVector)
		return (newVector);
	for (int i = 0; i < LA_2D; ++i)
		newVector.data[i] = pSourceVector->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

/*
** Addition vector --------------------------------------------------------------------------------
*/

vec2		laAdd2DVectors(vec2 *pLeftOperand, vec2 *pRightOperand, vec2 *pResultVector)
{
	vec2	newVector;

	if (!pLeftOperand || !pRightOperand)
		return (newVector);
	for (int i = 0; i < LA_2D; ++i)
		newVector.data[i] = pLeftOperand->data[i] + pRightOperand->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec3		laAdd3DVectors(vec3 *pLeftOperand, vec3 *pRightOperand, vec3 *pResultVector)
{
	vec3	newVector;

	if (!pLeftOperand || !pRightOperand)
		return (newVector);
	for (int i = 0; i < LA_3D; ++i)
		newVector.data[i] = pLeftOperand->data[i] + pRightOperand->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec4		laAdd4DVectors(vec4 *pLeftOperand, vec4 *pRightOperand, vec4 *pResultVector)
{
	vec4	newVector;

	if (!pLeftOperand || !pRightOperand)
		return (newVector);
	for (int i = 0; i < LA_4D; ++i)
		newVector.data[i] = pLeftOperand->data[i] + pRightOperand->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

/*
** Subtraction vector ---------------------------------------------------------------
*/

vec2		laSub2DVectors(vec2 *pLeftOperand, vec2 *pRightOperand, vec2 *pResultVector)
{
	vec2	newVector;

	if (!pLeftOperand || !pRightOperand)
		return (newVector);
	for (int i = 0; i < LA_2D; ++i)
		newVector.data[i] = pLeftOperand->data[i] - pRightOperand->data[i];
	if (pResultVector)
	{
		for (int i = 0; i < LA_2D; ++i)
			pResultVector->data[i] = newVector.data[i];
		return (*pResultVector);
	}
	return (newVector);
}

vec3		laSub3DVectors(vec3 *pLeftOperand, vec3 *pRightOperand, vec3 *pResultVector)
{
	vec3	newVector;

	if (!pLeftOperand || !pRightOperand)
		return (newVector);
	for (int i = 0; i < LA_3D; ++i)
		newVector.data[i] = pLeftOperand->data[i] - pRightOperand->data[i];
	if (pResultVector)
	{
		for (int i = 0; i < LA_3D; ++i)
			pResultVector->data[i] = newVector.data[i];
		return (*pResultVector);
	}
	return (newVector);
}

vec4		laSub4DVectors(vec4 *pLeftOperand, vec4 *pRightOperand, vec4 *pResultVector)
{
	vec4	newVector;

	if (!pLeftOperand || !pRightOperand)
		return (newVector);
	for (int i = 0; i < LA_4D; ++i)
		newVector.data[i] = pLeftOperand->data[i] - pRightOperand->data[i];
	if (pResultVector)
	{
		for (int i = 0; i < LA_4D; ++i)
			pResultVector->data[i] = newVector.data[i];
		return (*pResultVector);
	}
	return (newVector);
}

/*
** Magnitude vector -----------------------------------------------------------------
*/

float		laGetMagnitude2DVector(vec2 *pSourceVector, float *pResult)
{
	float	res;

	if (!pSourceVector)
		return (0.0f);
	res = sqrtf(powf(pSourceVector->data[LA_X], 2.0f)
					+ powf(pSourceVector->data[LA_Y], 2.0f));
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

float		laGetMagnitude3DVector(vec3 *pSourceVector, float *pResult)
{
	float	res;

	if (!pSourceVector)
		return (0.0f);
	res = sqrtf(powf(pSourceVector->data[LA_X], 2.0f)
					+ powf(pSourceVector->data[LA_Y], 2.0f)
						+ powf(pSourceVector->data[LA_Z], 2.0f));
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

float		laGetMagnitude4DVector(vec4 *pSourceVector, float *pResult)
{
	float	res;

	if (!pSourceVector)
		return (0.0f);
	res = sqrtf(powf(pSourceVector->data[LA_X], 2.0f)
					+ powf(pSourceVector->data[LA_Y], 2.0f)
						+ powf(pSourceVector->data[LA_Z], 2.0f)
							+ powf(pSourceVector->data[LA_W], 2.0f));
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

/*
** Normalize vector -----------------------------------------------------------------
*/

vec2		laNormalize2DVector(vec2 *pSourceVector, vec2 *pResultVector)
{
	vec2	newVector;
	float	length;

	if (!pSourceVector)
		return (newVector);
	length = 1 / sqrtf(powf(pSourceVector->data[LA_X], 2.0f)
						+ powf(pSourceVector->data[LA_Y], 2.0f));
	for (int i = 0; i < LA_2D; ++i)
		newVector.data[i] = pSourceVector->data[i] * length;
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec3		laNormalize3DVector(vec3 *pSourceVector, vec3 *pResultVector)
{
	vec3	newVector;
	float	length;

	if (!pSourceVector)
		return (newVector);
	length = 1 / sqrtf(powf(pSourceVector->data[LA_X], 2.0f)
						+ powf(pSourceVector->data[LA_Y], 2.0f)
							+ powf(pSourceVector->data[LA_Z], 2.0f));
	for (int i = 0; i < LA_3D; ++i)
		newVector.data[i] = pSourceVector->data[i] * length;
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec4		laNormalize4DVector(vec4 *pSourceVector, vec4 *pResultVector)
{
	vec4	newVector;
	float	length;

	if (!pSourceVector)
		return (newVector);
	length = 1 / sqrtf(powf(pSourceVector->data[LA_X], 2.0f)
						+ powf(pSourceVector->data[LA_Y], 2.0f)
							+ powf(pSourceVector->data[LA_Z], 2.0f)
								+ powf(pSourceVector->data[LA_W], 2.0f));
	for (int i = 0; i < LA_4D; ++i)
		newVector.data[i] = pSourceVector->data[i] * length;
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

/*
** Opposite vector -------------------------------------------------------------------
*/

vec2		laOpposite2DVector(vec2 *pSourceVector, vec2 *pResultVector)
{
	vec2	newVector;

	if (!pSourceVector)
		return (newVector);
	for (int i = 0; i < LA_2D; ++i)
		newVector.data[i] = -pSourceVector->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec3		laOpposite3DVector(vec3 *pSourceVector, vec3 *pResultVector)
{
	vec3	newVector;

	if (!pSourceVector)
		return (newVector);
	for (int i = 0; i < LA_3D; ++i)
		newVector.data[i] = -pSourceVector->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec4		laOpposite4DVector(vec4 *pSourceVector, vec4 *pResultVector)
{
	vec4	newVector;

	if (!pSourceVector)
		return (newVector);
	for (int i = 0; i < LA_4D; ++i)
		newVector.data[i] = -pSourceVector->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

/*
** Scalar Product vector ---------------------------------------------------------------
*/

vec2		laScalarProduct2DVector(vec2 *pSourceVector, float scalar, vec2 *pResultVector)
{
	vec2	newVector;

	if (!pSourceVector)
		return (newVector);
	for (int i = 0; i < LA_2D; ++i)
		newVector.data[i] = scalar * pSourceVector->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec3		laScalarProduct3DVector(vec3 *pSourceVector, float scalar, vec3 *pResultVector)
{
	vec3	newVector;

	if (!pSourceVector)
		return (newVector);
	for (int i = 0; i < LA_3D; ++i)
		newVector.data[i] = scalar * pSourceVector->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

vec4		laScalarProduct4DVector(vec4 *pSourceVector, float scalar, vec4 *pResultVector)
{
	vec4	newVector;

	if (!pSourceVector)
		return (newVector);
	for (int i = 0; i < LA_4D; ++i)
		newVector.data[i] = scalar * pSourceVector->data[i];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

/*
** Dot Product vector ------------------------------------------------------------------
*/

float		laDotProduct2DVectors(vec2 *pLeftVector, vec2 *pRightVector, float *pResult)
{
	float	res;

	res = 0.0f;
	if (!pLeftVector || !pRightVector)
		return (res);
	for (int i = 0; i < LA_2D; ++i)
		res += pLeftVector->data[i] * pRightVector->data[i];
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

float		laDotProduct3DVectors(vec3 *pLeftVector, vec3 *pRightVector, float *pResult)
{
	float	res;

	res = 0.0f;
	if (!pLeftVector || !pRightVector)
		return (res);
	for (int i = 0; i < LA_3D; ++i)
		res += pLeftVector->data[i] * pRightVector->data[i];
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

float		laDotProduct4DVectors(vec4 *pLeftVector, vec4 *pRightVector, float *pResult)
{
	float 	res;

	res = 0.0f;
	if (!pLeftVector || !pRightVector)
		return (res);
	for (int i = 0; i < LA_4D; ++i)
		res += pLeftVector->data[i] * pRightVector->data[i];
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

/*
** Cosine vector ----------------------------------------------------------------------
*/

float		laGetCosBetween2DVectors(vec2 *pLeftVector, vec2 *pRightVector, float *pResult)
{
	float	rightVectorLength;
	float	leftVectorLength;
	float	dotProduct;
	float	res;

	res = 0.0f;
	if (!pLeftVector || !pRightVector)
		return (res);
	for (int i = 0; i < LA_2D; ++i)
		res += pLeftVector->data[i] * pRightVector->data[i];
	rightVectorLength	= sqrtf(powf(pRightVector->data[LA_X], 2.0f)
								+ powf(pRightVector->data[LA_Y], 2.0f));
	leftVectorLength	= sqrtf(powf(pLeftVector->data[LA_X], 2.0f)
								+ powf(pLeftVector->data[LA_Y], 2.0f));
	res = res / (leftVectorLength * rightVectorLength);
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

float		laGetCosBetween3DVectors(vec3 *pLeftVector, vec3 *pRightVector, float *pResult)
{
	float	rightVectorLength;
	float	leftVectorLength;
	float	dotProduct;
	float	res;

	res = 0.0f;
	if (!pLeftVector || !pRightVector)
		return (res);
	for (int i = 0; i < LA_3D; ++i)
		res += pLeftVector->data[i] * pRightVector->data[i];
	rightVectorLength	= sqrtf(powf(pRightVector->data[LA_X], 2.0f)
									+ powf(pRightVector->data[LA_Y], 2.0f)
										+ powf(pRightVector->data[LA_Z], 2.0f));
	leftVectorLength	= sqrtf(powf(pLeftVector->data[LA_X], 2.0f)
									+ powf(pLeftVector->data[LA_Y], 2.0f)
										+ powf(pLeftVector->data[LA_Z], 2.0f));
	res = res / (leftVectorLength * rightVectorLength);
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

float	laGetCosBetween4DVectors(vec4 *pLeftVector, vec4 *pRightVector, float *pResult)
{
	float	rightVectorLength;
	float	leftVectorLength;
	float	dotProduct;
	float	res;

	res = 0.0f;
	if (!pLeftVector || !pRightVector)
		return (res);
	for (int i = 0; i < LA_4D; ++i)
		res += pLeftVector->data[i] * pRightVector->data[i];
	leftVectorLength	= sqrtf(powf(pLeftVector->data[LA_X], 2.0f)
								+ powf(pLeftVector->data[LA_Y], 2.0f)
									+ powf(pLeftVector->data[LA_Z], 2.0f)
										+ powf(pLeftVector->data[LA_W], 2.0f));
	rightVectorLength	= sqrtf(powf(pRightVector->data[LA_X], 2.0f)
								+ powf(pRightVector->data[LA_Y], 2.0f)
									+ powf(pRightVector->data[LA_Z], 2.0f)
										+ powf(pRightVector->data[LA_W], 2.0f));
	res = dotProduct / (leftVectorLength * rightVectorLength);
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

/*
** Cross Product vector ---------------------------------------------------------------
*/

void		laCrossProduct3DVectors(vec3 *pBasisVector, vec3 *pLeftVector, vec3 *pRightVector, vec3 *pResultVector)
{
	mat3	matrix;
	vec3	basisVec;
	float	det;
	float	subMatrix[3];

	if (!pLeftVector || !pRightVector)
		return ;
	if (!pBasisVector)
		laInit3DVector(&basisVec, 1.0f, 1.0f, 1.0f, NULL);
	else
		basisVec = *pBasisVector;
	laInit3DMatrix(&matrix, &basisVec, pLeftVector, pRightVector, (void *)0, (void *)0);
	laGetDeterminant3DMatrix(&matrix, &det, subMatrix);
	pResultVector->data[LA_X] = subMatrix[0];
	pResultVector->data[LA_Y] = -subMatrix[1];
	pResultVector->data[LA_Z] = subMatrix[2];

}

/*
** Multiply vector by matrix
*/

vec3		laMul3DVectorByMatrix(vec3 *pSourceVector, mat3 *pSourceMatrix, vec3 *pResultVector)
{
	vec3	newVector;

	if (!pSourceVector || !pSourceMatrix)
		return (newVector);
	for (int i = 0; i < LA_3D; ++i)
		newVector.data[i] = pSourceVector->data[LA_X] * pSourceMatrix->data[i][LA_X]
								+ pSourceVector->data[LA_Y] * pSourceMatrix->data[i][LA_Y]
									+ pSourceVector->data[LA_Z] * pSourceMatrix->data[i][LA_Z];
	if (pResultVector)
	{
		*pResultVector = newVector;
		return (*pResultVector);
	}
	return (newVector);
}

/*
** Main for testing -------------------------------------------------------------------
*/

// int main(int argc, char **argv)
// {
// 	vec3	one;
// 	vec3	two;
// 	float	z;
// 	float	z1;
// 	float	res;
// 	float	result;

// 	laInit3DVector(&one, 3.0f, 1.0f, 7.0f, NULL);
// 	laInit3DVector(&two, 7.0f, 4.0f, 2.0f, NULL);
// 	//printf("%10f %10f %10f\n", one.data[LA_X], one.data[LA_Y], one.data[LA_Z]);
// 	//printf("%10f %10f %10f\n", two.data[LA_X], two.data[LA_Y], two.data[LA_Z]);
// 	//laOpposite3DVector(&two, &two);
// 	//laOpposite3DVector(&one, &one);
// 	//laNormalize3DVector(&one, &one);
// 	//laNormalize3DVector(&two, &two);
// 	laGetMagnitude3DVector(&one, &z);
// 	laGetMagnitude3DVector(&two, &z1);
// 	//printf("%10f %10f %10f\n", one.data[LA_X], one.data[LA_Y], one.data[LA_Z]);
// 	//printf("%10f %10f %10f\n", two.data[LA_X], two.data[LA_Y], two.data[LA_Z]);
// 	laDotProduct3DVectors(&one , &two, &res);
// 	laGetCosBetween3DVectors(&one, &two, &result);
// 	printf("%f\n", res);
// 	printf("%f\n", result * z * z1);
// }