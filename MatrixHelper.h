#ifndef MATRIX_HELPER_H
#define MATRIX_HELPER_H

namespace MatrixHelper {
	GW::MATH::GVECTORF Forward(GW::MATH::GMatrix& matrixProxy, GW::MATH::GVector& vectorProxy, const GW::MATH::GMATRIXF& matrix) {
		GW::MATH::GMATRIXF inv;
		matrixProxy.InverseF(matrix, inv);
		GW::MATH::GVECTORF norm = { inv.row3.data[0], inv.row3.data[1], inv.row3.data[2] } ;
		vectorProxy.NormalizeF(norm, norm);
		return norm;
	}

	GW::MATH::GVECTORF Up(GW::MATH::GMatrix& matrixProxy, GW::MATH::GVector& vectorProxy, const GW::MATH::GMATRIXF& matrix) {
		GW::MATH::GMATRIXF inv;
		matrixProxy.InverseF(matrix, inv);
		GW::MATH::GVECTORF norm = { inv.row2.data[0], inv.row2.data[1], inv.row2.data[2] };
		vectorProxy.NormalizeF(norm, norm);
		return norm;
	}

	GW::MATH::GVECTORF Left(GW::MATH::GMatrix& matrixProxy, GW::MATH::GVector& vectorProxy, const GW::MATH::GMATRIXF& matrix) {
		GW::MATH::GMATRIXF inv;
		matrixProxy.InverseF(matrix, inv);
		GW::MATH::GVECTORF norm = { inv.row1.data[0], inv.row1.data[1], inv.row1.data[2] };
		vectorProxy.NormalizeF(norm, norm);
		return norm;
	}
}

#endif