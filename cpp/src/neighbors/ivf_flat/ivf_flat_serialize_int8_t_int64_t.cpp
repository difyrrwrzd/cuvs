/*
 * Copyright (c) 2024, NVIDIA CORPORATION.
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

/*
 * NOTE: this file is generated by generate_ivf_flat.py
 *
 * Make changes there and run in this directory:
 *
 * > python generate_ivf_flat.py
 *
 */

#include <cuvs/neighbors/ivf_flat.hpp>
#include <raft_runtime/neighbors/ivf_flat.hpp>

namespace cuvs::neighbors::ivf_flat {

#define CUVS_INST_IVF_FLAT_SERIALIZE(T, IdxT)                                                      \
  void serialize_file(raft::resources const& handle,                                               \
                      const std::string& filename,                                                 \
                      const cuvs::neighbors::ivf_flat::index<T, IdxT>& index)                      \
  {                                                                                                \
    raft::runtime::neighbors::ivf_flat::serialize_file(handle, filename, *index.get_raft_index()); \
  }                                                                                                \
                                                                                                   \
  void deserialize_file(raft::resources const& handle,                                             \
                        const std::string& filename,                                               \
                        cuvs::neighbors::ivf_flat::index<T, IdxT>* index)                          \
  {                                                                                                \
    raft::runtime::neighbors::ivf_flat::deserialize_file(                                          \
      handle, filename, index->get_raft_index());                                                  \
  }                                                                                                \
                                                                                                   \
  void serialize(raft::resources const& handle,                                                    \
                 std::string& str,                                                                 \
                 const cuvs::neighbors::ivf_flat::index<T, IdxT>& index)                           \
  {                                                                                                \
    raft::runtime::neighbors::ivf_flat::serialize(handle, str, *index.get_raft_index());           \
  }                                                                                                \
                                                                                                   \
  void deserialize(raft::resources const& handle,                                                  \
                   const std::string& str,                                                         \
                   cuvs::neighbors::ivf_flat::index<T, IdxT>* index)                               \
  {                                                                                                \
    raft::runtime::neighbors::ivf_flat::deserialize(handle, str, index->get_raft_index());         \
  }
CUVS_INST_IVF_FLAT_SERIALIZE(int8_t, int64_t);

#undef CUVS_INST_IVF_FLAT_SERIALIZE

}  // namespace cuvs::neighbors::ivf_flat
