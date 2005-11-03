// $Id$

#ifndef TAO_TYPECODE_CASE_CPP
#define TAO_TYPECODE_CASE_CPP

#include "TypeCode_Case_Base_T.h"
#include "ace/OS_NS_string.h"

#ifndef __ACE_INLINE__
# include "tao/AnyTypeCode/TypeCode_Case_Base_T.inl"
#endif /* __ACE_INLINE__ */

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

template <typename StringType, typename TypeCodeType>
TAO::TypeCode::Case<StringType, TypeCodeType>::~Case (void)
{
}

template <typename StringType, typename TypeCodeType>
bool
TAO::TypeCode::Case<StringType, TypeCodeType>::equal (CORBA::ULong index,
                                                      CORBA::TypeCode_ptr tc
                                                      ACE_ENV_ARG_DECL) const
{
  // Check case names.
  char const * const lhs_name = this->name ();
  char const * const rhs_name = tc->member_name (index
                                                 ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (ACE_OS::strcmp (lhs_name, rhs_name) != 0)
    return 0;

  // Check case TypeCodes.
  CORBA::TypeCode_ptr const lhs_tc = this->type ();
  CORBA::TypeCode_var const rhs_tc =
    tc->member_type (index
                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Boolean const equal_members =
    lhs_tc->equal (rhs_tc.in ()
                   ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (!equal_members)
    return 0;

  // Check case label.
  return this->equal_label (index,
                            tc
                            ACE_ENV_ARG_PARAMETER);
}

template <typename StringType, typename TypeCodeType>
bool
TAO::TypeCode::Case<StringType, TypeCodeType>::equivalent (
  CORBA::ULong index,
  CORBA::TypeCode_ptr tc
  ACE_ENV_ARG_DECL) const
{
  // Member names are ignore when determining equivalence.

  // Check case TypeCodes.
  CORBA::TypeCode_ptr const lhs_tc = this->type ();
  CORBA::TypeCode_var const rhs_tc =
    tc->member_type (index
                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  CORBA::Boolean const equivalent_members =
    lhs_tc->equivalent (rhs_tc.in ()
                        ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (0);

  if (!equivalent_members)
    return 0;

  // Check case label.
  // The label must be equal when determining equivalence, too.
  return this->equal_label (index,
                            tc
                            ACE_ENV_ARG_PARAMETER);
}

TAO_END_VERSIONED_NAMESPACE_DECL

#endif  /* TAO_TYPECODE_CASE_CPP */
