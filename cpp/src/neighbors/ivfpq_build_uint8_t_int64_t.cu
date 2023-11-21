/*
 * Copyright (c) 2023, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cuvs/neighbors/ivf_pq-inl.cuh>
#include <cuvs/neighbors/ivf_pq_types.hpp>  // cuvs::neighbors::ivf_pq::index

#define instantiate_raft_neighbors_ivf_pq_build(T, IdxT)                                 \
  template cuvs::neighbors::ivf_pq::index<IdxT> cuvs::neighbors::ivf_pq::build<T, IdxT>( \
    raft::resources const& handle,                                                       \
    const cuvs::neighbors::ivf_pq::index_params& params,                                 \
    raft::device_matrix_view<const T, IdxT, raft::row_major> dataset);                   \
                                                                                         \
  template auto cuvs::neighbors::ivf_pq::build(                                          \
    raft::resources const& handle,                                                       \
    const cuvs::neighbors::ivf_pq::index_params& params,                                 \
    const T* dataset,                                                                    \
    IdxT n_rows,                                                                         \
    uint32_t dim)                                                                        \
    ->cuvs::neighbors::ivf_pq::index<IdxT>;

instantiate_raft_neighbors_ivf_pq_build(uint8_t, int64_t);

#undef instantiate_raft_neighbors_ivf_pq_build
