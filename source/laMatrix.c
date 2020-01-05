/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laMatrix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Rustam <super.rustamm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:45:14 by vrichese          #+#    #+#             */
/*   Updated: 2019/12/10 17:51:28 by Rustam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LLFC.h"

/*
** Initialization matrix ------------------------------------------------------------------------------------------------
*/

mat2		laInit2DMatrix(mat2 *pSourceMatrix, vec2 *pFirstVector, vec2 *pSecondVector,
						float *pInitArray, float *pOneValue)
{
	mat2	newMatrix;

	if (pFirstVector && pSecondVector)
		for (int y = 0; y < LA_2D; ++y)
		{
			newMatrix.data[y][LA_X] = pFirstVector->data[y];
			newMatrix.data[y][LA_Y] = pSecondVector->data[y];
		}
	else if (pInitArray)
		for (int y = 0; y < LA_2D; ++y)
			for (int x = 0; x < LA_2D; ++x)
				newMatrix.data[y][x] = pInitArray[x + (y * LA_2D)];
	else if (pOneValue)
		for (int y = 0; y < LA_2D; ++y)
			for(int x = 0; x < LA_2D; ++x)
				newMatrix.data[y][x] = *pOneValue;
	if (pSourceMatrix)
	{
		*pSourceMatrix = newMatrix;
		return (*pSourceMatrix);
	}
	return (newMatrix);
}

mat3		laInit3DMatrix(mat3 *pSourceMatrix, vec3 *pFirstVector, vec3 *pSecondVector,
						vec3 *pThirdVector, float *pInitArray, float *pOneValue)
{
	mat3	newMatrix;

	if (pFirstVector && pSecondVector && pThirdVector)
		for (int y = 0; y < LA_3D; ++y)
		{
			newMatrix.data[y][LA_X] = pFirstVector->data[y];
			newMatrix.data[y][LA_Y] = pSecondVector->data[y];
			newMatrix.data[y][LA_Z] = pThirdVector->data[y];
		}
	else if (pInitArray)
		for (int y = 0; y < LA_3D; ++y)
			for (int x = 0; x < LA_3D; ++x)
				newMatrix.data[y][x] = pInitArray[x + (y * LA_3D)];
	else if (pOneValue)
		for (int y = 0; y < LA_3D; ++y)
			for(int x = 0; x < LA_3D; ++x)
				newMatrix.data[y][x] = *pOneValue;
	if (pSourceMatrix)
	{
		*pSourceMatrix = newMatrix;
		return (*pSourceMatrix);
	}
	return (newMatrix);
}

mat4		laInit4DMatrix(mat4 *pSourceMatrix, vec4 *pFirstVector, vec4 *pSecondVector,
						vec4 *pThirdVector, vec4 *pFourthVector, float *pInitArray, float *pOneValue)
{
	mat4	newMatrix;

	if (pFirstVector && pSecondVector && pThirdVector && pFourthVector)
		for (int y = 0; y < 4; ++y)
		{
			newMatrix.data[y][LA_X] = pFirstVector->data[y];
			newMatrix.data[y][LA_Y] = pSecondVector->data[y];
			newMatrix.data[y][LA_Z] = pThirdVector->data[y];
			newMatrix.data[y][LA_W] = pFourthVector->data[y];
		}
	else if (pOneValue)
		for (int y = 0; y < LA_4D; ++y)
			for (int x = 0; x < LA_4D; ++x)
				newMatrix.data[y][x] = pInitArray[x + (y * LA_4D)];
	else if (pOneValue)
		for (int y = 0; y < LA_4D; ++y)
			for (int x = 0; x < LA_4D; ++x)
				newMatrix.data[y][x] = *pOneValue;
	if (pSourceMatrix)
	{
		*pSourceMatrix = newMatrix;
		return (*pSourceMatrix);
	}
	return (newMatrix);
}

/*
** Copy matrix ----------------------------------------------------------------------------------------
*/

mat2		laCopy2DMatrix(mat2 *pSourceMatrix, mat2 *pResultMatrix)
{
	mat2	newMatrix;

	if (!pSourceMatrix)
		return (newMatrix);
	if (pResultMatrix)
	{
		for (int y = 0; y < LA_2D; ++y)
			for(int x = 0; x < LA_2D; ++x)
				pResultMatrix->data[y][x] = pSourceMatrix->data[y][x];
		return (*pResultMatrix);
	}
	else
	{
		for (int y = 0; y < LA_2D; ++y)
			for(int x = 0; x < LA_2D; ++x)
				newMatrix.data[y][x] = pSourceMatrix->data[y][x];
		return (newMatrix);
	}
}

mat3	laCopy3DMatrix(mat3 *pSourceMatrix, mat3 *pResultMatrix)
{
	mat3	newMatrix;

	if (!pSourceMatrix)
		return (newMatrix);
	if (pResultMatrix)
	{
		for (int y = 0; y < LA_3D; ++y)
			for(int x = 0; x < LA_3D; ++x)
				pResultMatrix->data[y][x] = pSourceMatrix->data[y][x];
		return (*pResultMatrix);
	}
	else
	{
		for (int y = 0; y < LA_3D; ++y)
			for(int x = 0; x < LA_3D; ++x)
				newMatrix.data[y][x] = pSourceMatrix->data[y][x];
		return (newMatrix);
	}
}

mat4	laCopy4DMatrix(mat4 *pSourceMatrix, mat4 *pResultMatrix)
{
	mat4	newMatrix;

	if (!pSourceMatrix)
		return (newMatrix);
	if (pResultMatrix)
	{
		for (int y = 0; y < LA_4D; ++y)
			for(int x = 0; x < LA_4D; ++x)
				pResultMatrix->data[y][x] = pSourceMatrix->data[y][x];
		return (*pResultMatrix);
	}
	else
	{
		for (int y = 0; y < LA_4D; ++y)
			for(int x = 0; x < LA_4D; ++x)
				newMatrix.data[y][x] = pSourceMatrix->data[y][x];
		return (newMatrix);
	}
}

/*
** Addition matrix ------------------------------------------------------------------------------------
*/

void	laAdd2DMatrix(mat2 *pLeftOperand, mat2 *pRightOperand, mat2 *pResultMatrix)
{
	if (!pResultMatrix || !pLeftOperand || !pRightOperand)
		return ;
	for (int y = 0; y < LA_2D; ++y)
	{
		pResultMatrix->data[y][LA_X] = pLeftOperand->data[y][LA_X] + pRightOperand->data[y][LA_X];
		pResultMatrix->data[y][LA_Y] = pLeftOperand->data[y][LA_Y] + pRightOperand->data[y][LA_Y];
	}

}

void	laAdd3DMatrix(mat3 *pLeftOperand, mat3 *pRightOperand, mat3 *pResultMatrix)
{
	if (!pResultMatrix || !pLeftOperand || !pRightOperand)
		return ;
	for (int y = 0; y < LA_3D; ++y)
	{
		pResultMatrix->data[y][LA_X] = pLeftOperand->data[y][LA_X] + pRightOperand->data[y][LA_X];
		pResultMatrix->data[y][LA_Y] = pLeftOperand->data[y][LA_Y] + pRightOperand->data[y][LA_Y];
		pResultMatrix->data[y][LA_Z] = pLeftOperand->data[y][LA_Z] + pRightOperand->data[y][LA_Z];
	}
}

void	laAdd4DMatrix(mat4 *pLeftOperand, mat4 *pRightOperand, mat4 *pResultMatrix)
{
	if (!pResultMatrix || !pLeftOperand || !pRightOperand)
		return ;
	for (int y = 0; y < LA_4D; ++y)
	{
		pResultMatrix->data[y][LA_X] = pLeftOperand->data[y][LA_X] + pRightOperand->data[y][LA_X];
		pResultMatrix->data[y][LA_Y] = pLeftOperand->data[y][LA_Y] + pRightOperand->data[y][LA_Y];
		pResultMatrix->data[y][LA_Z] = pLeftOperand->data[y][LA_Z] + pRightOperand->data[y][LA_Z];
		pResultMatrix->data[y][LA_W] = pLeftOperand->data[y][LA_W] + pRightOperand->data[y][LA_W];
	}
}

/*
** Subtraction matrix ----------------------------------------------------------------------------------
*/

void	laSub2DMatrix(mat2 *pLeftOperand, mat2 *pRightOperand, mat2 *pResultMatrix)
{
	if (!pResultMatrix || !pLeftOperand || !pRightOperand)
		return ;
	for (int y = 0; y < LA_2D; ++y)
	{
		pResultMatrix->data[y][LA_X] = pLeftOperand->data[y][LA_X] - pRightOperand->data[y][LA_X];
		pResultMatrix->data[y][LA_Y] = pLeftOperand->data[y][LA_Y] - pRightOperand->data[y][LA_Y];
	}
}

void	laSub3DMatrix(mat3 *pLeftOperand, mat3 *pRightOperand, mat3 *pResultMatrix)
{
	if (!pResultMatrix || !pLeftOperand || !pRightOperand)
		return ;
	for (int y = 0; y < LA_3D; ++y)
	{
		pResultMatrix->data[y][LA_X] = pLeftOperand->data[y][LA_X] - pRightOperand->data[y][LA_X];
		pResultMatrix->data[y][LA_Y] = pLeftOperand->data[y][LA_Y] - pRightOperand->data[y][LA_Y];
		pResultMatrix->data[y][LA_Z] = pLeftOperand->data[y][LA_Z] - pRightOperand->data[y][LA_Z];
	}
}

void	laSub4DMatrix(mat4 *pLeftOperand, mat4 *pRightOperand, mat4 *pResultMatrix)
{
	if (!pResultMatrix || !pLeftOperand || !pRightOperand)
		return ;
	for (int y = 0; y < LA_4D; ++y)
	{
		pResultMatrix->data[y][LA_X] = pLeftOperand->data[y][LA_X] - pRightOperand->data[y][LA_X];
		pResultMatrix->data[y][LA_Y] = pLeftOperand->data[y][LA_Y] - pRightOperand->data[y][LA_Y];
		pResultMatrix->data[y][LA_Z] = pLeftOperand->data[y][LA_Z] - pRightOperand->data[y][LA_Z];
		pResultMatrix->data[y][LA_W] = pLeftOperand->data[y][LA_W] - pRightOperand->data[y][LA_W];
	}
}

/*
** Determinant matrix ---------------------------------------------------------------------------------
*/

float		laGetDeterminant2DMatrix(mat2 *pSourceMatrix, float *pResult)
{
	float	res;

	res = 0.0f;
	if (!pSourceMatrix)
		return (res);
	res = pSourceMatrix->data[LA_X][LA_X] * pSourceMatrix->data[LA_Y][LA_Y]
			- pSourceMatrix->data[LA_X][LA_Y] * pSourceMatrix->data[LA_Y][LA_X];
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

float		laGetDeterminant3DMatrix(mat3 *pSourceMatrix, float *pResult, float *pSubMatrixArray)
{
	mat2	topSubMatrix;
	mat2	middleSubMatrix;
	mat2	bottomSubMatrix;
	float	res;

	res = 0.0f;
	for(int y = 0; y < 2; ++y)
		for (int x = 0; x < 2; ++x)
		{
			topSubMatrix.data[y][x]		= pSourceMatrix->data[y][x + 1];
			bottomSubMatrix.data[y][x]	= pSourceMatrix->data[y + 1][x + 1];
			middleSubMatrix.data[y][x]	= pSourceMatrix->data[y + (y % 2)][x + 1];
		}
	res = pSourceMatrix->data[LA_X][LA_X] * laGetDeterminant2DMatrix(&middleSubMatrix, NULL)
			+ -pSourceMatrix->data[LA_Y][LA_X] * laGetDeterminant2DMatrix(&bottomSubMatrix, NULL)
				+ pSourceMatrix->data[LA_Z][LA_X] * laGetDeterminant2DMatrix(&topSubMatrix, NULL);
	if (pSubMatrixArray)
	{
		pSubMatrixArray[0] = laGetDeterminant2DMatrix(&middleSubMatrix, NULL);
		pSubMatrixArray[1] = laGetDeterminant2DMatrix(&bottomSubMatrix, NULL);
		pSubMatrixArray[2] = laGetDeterminant2DMatrix(&topSubMatrix, NULL);
	}
	if (pResult)
	{
		*pResult = res;
		return (*pResult);
	}
	return (res);
}

// float	laGetDeterminant4DMatrix(mat4 *pSourceMatrix, float *pResult, float *pSubMatrixArray)
// {
// 	mat3	topSubMatrix;
// 	mat3	middleSubFirstMatrix;
// 	mat3	middleSubSecondMatrix;
// 	mat3	bottomSubMatrix;
// 	float	firstResult;
// 	float	secondResult;
// 	float	thirdResult;
// 	float	fourthResult;
// 	int		x;
// 	int		y;

// 	y = -1;
// 	while (++y < 3 && (x = - 1))
// 		while(++x < 3)
// 		{
// 			topSubMatrix.data[y][x]				= pSourceMatrix->data[y][x + 1];
// 			middleSubFirstMatrix.data[y][x]		= pSourceMatrix->data[y + (y > 0)][x + 1];
// 			middleSubSecondMatrix.data[y][x]	= pSourceMatrix->data[y + (y > 1)][x + 1];
// 			bottomSubMatrix.data[y][x]			= pSourceMatrix->data[y + 1][x + 1];
// 		}
// 	laGetDeterminant3DMatrix(&bottomSubMatrix, &firstResult, NULL);
// 	laGetDeterminant3DMatrix(&middleSubFirstMatrix, &secondResult, NULL);
// 	laGetDeterminant3DMatrix(&middleSubSecondMatrix, &thirdResult, NULL);
// 	laGetDeterminant3DMatrix(&topSubMatrix, &fourthResult, NULL);
// 	*pResult = pSourceMatrix->data[LA_X][LA_X] * firstResult
// 				+ -pSourceMatrix->data[LA_Y][LA_X] * secondResult
// 					+ pSourceMatrix->data[LA_Z][LA_X] * thirdResult
// 						+ -pSourceMatrix->data[LA_W][LA_X] * fourthResult;
// 	if (pSubMatrixArray)
// 	{
// 		pSubMatrixArray[0] = firstResult;
// 		pSubMatrixArray[1] = secondResult;
// 		pSubMatrixArray[2] = thirdResult;
// 		pSubMatrixArray[3] = fourthResult;
// 	}
// }

/*
** Opposite matrix ----------------------------------------------------------------------------------
*/

// mat2		laOpposite2DMatrix(mat2 *pSourceMatrix, mat2 *pResultMatrix)
// {
// 	mat2	newMatrix;
// 	float	detMat;

// 	if (!pSourceMatrix)
// 		return newMatrix;
// 	detMat =
// }

/*
** Multiply matrix ----------------------------------------------------------------------------------
*/

mat3		laMul3Dmatrix(mat3 *pLeftOperand, mat3 *pRightOperand, mat3 *pResultMatrix)
{
	mat3	newMatrix;
	float	fill = 0.0f;

	laInit3DMatrix(&newMatrix, NULL, NULL, NULL, NULL, &fill);
	if (!pLeftOperand || !pRightOperand)
		return (newMatrix);
	for (int y = 0; y < LA_3D; ++y)
		for(int x = 0; x < LA_3D; ++x)
			for (int i = 0; i < LA_3D; ++i)
				newMatrix.data[y][x] += pLeftOperand->data[i][x] * pRightOperand->data[y][i];
	if (pResultMatrix)
	{
		*pResultMatrix = newMatrix;
		return (*pResultMatrix);
	}
	return (newMatrix);
}

/*
** Some Transoformation matrix ----------------------------------------------------------------------
*/

void	laXaxisRotation(mat3 *pSourceMatrix, float *pAngle)
{
	float null;

	if (!pSourceMatrix || !pAngle)
		return ;
	null = 0.0f;
	laInit3DMatrix(pSourceMatrix, NULL, NULL, NULL, NULL, &null);
	pSourceMatrix->data[LA_Y][LA_Y] += cosf(*pAngle);
	pSourceMatrix->data[LA_Z][LA_Y] += -sinf(*pAngle);
	pSourceMatrix->data[LA_Y][LA_Z] += sinf(*pAngle);
	pSourceMatrix->data[LA_Z][LA_Z] += cos(*pAngle);
	pSourceMatrix->data[LA_X][LA_X] += 1.0f;
}

void	laYaxisRotation(mat3 *pSourceMatrix, float *pAngle)
{
	float null;

	if (!pSourceMatrix || !pAngle)
		return ;
	null = 0.0f;
	laInit3DMatrix(pSourceMatrix, NULL, NULL, NULL, NULL, &null);
	pSourceMatrix->data[LA_X][LA_X] += cosf(*pAngle);
	pSourceMatrix->data[LA_Z][LA_X] += sinf(*pAngle);
	pSourceMatrix->data[LA_X][LA_Z] += -sinf(*pAngle);
	pSourceMatrix->data[LA_Z][LA_Z] += cosf(*pAngle);
	pSourceMatrix->data[LA_Y][LA_Y] += 1.0f;
}

void	laZaxisRotation(mat3 *pSourceMatrix, float *pAngle)
{
	float null;

	if (!pSourceMatrix || !pAngle)
		return ;
	null = 0.0f;
	laInit3DMatrix(pSourceMatrix, NULL, NULL, NULL, NULL, &null);
	pSourceMatrix->data[LA_X][LA_X] += cosf(*pAngle);
	pSourceMatrix->data[LA_Y][LA_X] += sinf(*pAngle);
	pSourceMatrix->data[LA_X][LA_Y] += -sinf(*pAngle);
	pSourceMatrix->data[LA_Y][LA_Y] += cosf(*pAngle);
	pSourceMatrix->data[LA_Z][LA_Z] += 1.0f;
}

void	laRotate(mat3 *pSourceMatrix, vec3 *pRotateVector)
{
	mat3	xRot;
	mat3	yRot;
	mat3	zRot;
	mat3	xyzRot;
	float	null;

	null = 0.0f;
	laXaxisRotation(&xRot, &pRotateVector->data[LA_X]);
	laYaxisRotation(&yRot, &pRotateVector->data[LA_Y]);
	laZaxisRotation(&zRot, &pRotateVector->data[LA_Z]);
	laInit3DMatrix(&xyzRot, NULL, NULL, NULL, NULL, &null);
	laMul3Dmatrix(&xRot, &yRot, &xyzRot);
	laMul3Dmatrix(&zRot, &xyzRot, &xyzRot);
	laMul3Dmatrix(&xyzRot, pSourceMatrix, pSourceMatrix);
}

/*
** Scale matrix --------------------------------------------------------------------------------------
*/

mat2		laScale2DMatrix(mat2 *pSourceMatrix, vec2 *pScaleVector, mat2 *pResultMatrix, float *pScale)
{
	mat2	newMatrix;

	if (!pSourceMatrix)
		return (newMatrix);
	if (pScaleVector)
		for (int i = 0; i < LA_2D; ++i)
			newMatrix.data[i][i] = pSourceMatrix->data[i][i] * pScaleVector->data[i];
	else if (pScale)
		for (int i = 0; i < LA_2D; ++i)
			newMatrix.data[i][i] = pSourceMatrix->data[i][i] * *pScale;
	if (pResultMatrix)
	{
		*pResultMatrix = newMatrix;
		return (*pResultMatrix);
	}
	return (newMatrix);
}

mat3		laScale3DMatrix(mat3 *pSourceMatrix, vec3 *pScaleVector, mat3 *pResultMatrix, float *pScale)
{
	mat3	newMatrix;

	if (!pSourceMatrix)
		return (newMatrix);
	if (pScaleVector)
		for (int i = 0; i < LA_3D; ++i)
			newMatrix.data[i][i] = pSourceMatrix->data[i][i] * pScaleVector->data[i];
	else if (pScale)
		for (int i = 0; i < LA_3D; ++i)
			newMatrix.data[i][i] = pSourceMatrix->data[i][i] * *pScale;
	if (pResultMatrix)
	{
		*pResultMatrix = newMatrix;
		return (*pResultMatrix);
	}
	return (newMatrix);
}

mat4		laScale4DMatrix(mat4 *pSourceMatrix, vec4 *pScaleVector, mat4 *pResultMatrix, float *pScale)
{
	mat4	newMatrix;

	if (!pSourceMatrix)
		return (newMatrix);
	if (pScaleVector)
		for (int i = 0; i < LA_4D; ++i)
			newMatrix.data[i][i] = pSourceMatrix->data[i][i] * pScaleVector->data[i];
	else if (pScale)
		for (int i = 0; i < LA_4D; ++i)
			newMatrix.data[i][i] = pSourceMatrix->data[i][i] * *pScale;
	if (pResultMatrix)
	{
		*pResultMatrix = newMatrix;
		return (*pResultMatrix);
	}
	return (newMatrix);
}

/*
** For testing ---------------------------------------------------------------------------------------
*/

// int main(int argc, char **argv)
// {
// 	vec3 one;
// 	vec3 two;
// 	vec3 three;
// 	vec3 rot;
// 	mat3 matrix;
// 	mat3 test;

// 	laInit3DVector(&one, 1.0f, 0.0f, 0.0f, NULL);
// 	laInit3DVector(&two, 0.0f, 1.0f, 0.0f, NULL);
// 	laInit3DVector(&three, 0.0f, 0.0f, 1.0f, NULL);
// 	laInit3DVector(&rot, 100.0f, 2.0f, 0.0f, NULL);
// 	laInit3DMatrix(&matrix, &one, &two, &three, NULL, NULL);
// 	laRotate(&matrix, &rot);
// 	laInit3DVector(&rot, 3.0f, 0.0f, 0.0f, NULL);
// 	laMul3DVectorByMatrix(&rot, &matrix, &rot);
// 	printf("%f %f %f\n", rot.data[LA_X], rot.data[LA_Y], rot.data[LA_Z]);
// 	exit(1);
// 	for (int y = 0; y < 3; ++y)
// 	{
// 		for (int x = 0; x < 3; ++x)
// 			printf("%f ", matrix.data[y][x]);
// 		printf("\n");
// 	}
// 	return (0);
// }