#pragma once

// Indexing tensors by by tensors

#include <ATen/ATen.h>
#include <ATen/native/DispatchStub.h>

namespace at {
  struct TensorIterator;
}

namespace at { namespace native {

using index_fn = void(*)(TensorIterator &, IntArrayRef indexed_sizes, IntArrayRef indexed_strides);
using index_put_fn = void(*)(TensorIterator &, IntArrayRef indexed_sizes, IntArrayRef indexed_strides, bool accumulate);
using index_put_accum_fn = void(*)(Tensor &, TensorList , const Tensor &, bool unsafe);
using masked_fill_fn = void(*)(TensorIterator &, Scalar scalar);

using gather_fn = void (*)(Tensor & result, const Tensor & self, int64_t dim, const Tensor & index, int64_t force_heuristic);
using scatter_fn = void(*)(Tensor& self, int64_t dim, const Tensor& index, const Tensor& src, int64_t force_heuristic);
using scatter_fill_fn = void(*)(Tensor& self, int64_t dim, const Tensor& index, Scalar src, int64_t force_heuristic);
using scatter_add_fn = void(*)(Tensor& self, int64_t dim, const Tensor& index, const Tensor& src, int64_t force_heuristic);

DECLARE_DISPATCH(index_fn, index_stub);
DECLARE_DISPATCH(index_put_fn, index_put_stub);
DECLARE_DISPATCH(index_put_accum_fn, index_put_accum_stub);
DECLARE_DISPATCH(masked_fill_fn, masked_fill_stub);

DECLARE_DISPATCH(gather_fn, gather_stub);
DECLARE_DISPATCH(scatter_fn, scatter_stub);
DECLARE_DISPATCH(scatter_fill_fn, scatter_fill_stub);
DECLARE_DISPATCH(scatter_add_fn, scatter_add_stub);

using index_select_kernel_fn = gather_fn;
DECLARE_DISPATCH(index_select_kernel_fn, index_select_kernel_stub);

TORCH_API Tensor& index_out(Tensor& result, const Tensor & self, TensorList indices);

}} // namespace at::native
