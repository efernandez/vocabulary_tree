#ifndef VOCABULARY_TREE_FEATURE_ALLOCATOR_H
#define VOCABULARY_TREE_FEATURE_ALLOCATOR_H

#include <Eigen/Core>
#include <Eigen/StdVector>

namespace vt {

/**
 * \brief Meta-function to get the default allocator for a particular feature type.
 *
 * Defaults to \c std::allocator<Feature>.
 */
template<class Feature>
struct DefaultAllocator
{
  typedef std::allocator<Feature> type;
};

// Specialization to use aligned allocator for Eigen::Matrix types.
template<typename Scalar, int Rows, int Cols, int Options, int MaxRows, int MaxCols>
struct DefaultAllocator< Eigen::Matrix<Scalar, Rows, Cols, Options, MaxRows, MaxCols> >
{
  typedef Eigen::aligned_allocator<Eigen::Matrix<Scalar, Rows, Cols, Options, MaxRows, MaxCols> > type;
};

} //namespace vt

#endif
