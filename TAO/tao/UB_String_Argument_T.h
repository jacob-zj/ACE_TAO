// -*- C++ -*-

//=============================================================================
/**
 *  @file    UB_String_Argument_T.h
 *
 *  $Id$
 *
 *  @authors Jeff Parsons, Carlos O'Ryan and Ossama Othman
 */
//=============================================================================

#ifndef TAO_UB_STRING_ARGUMENT_T_H
#define TAO_UB_STRING_ARGUMENT_T_H

#include /**/ "ace/pre.h"

#include "tao/Argument_T.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

namespace TAO
{
  /**
   * @class In_UB_String_Argument_T
   *
   * @brief Template class for IN unbounded (w)string argument.
   *
   */
  template<typename S>
  class In_UB_String_Argument_T : public Const_Argument_T<S const *>
  {
  public:
    In_UB_String_Argument_T (const S * x);

    virtual CORBA::Boolean marshal (TAO_OutputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_param (Dynamic::Parameter &);
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    virtual S const * arg (void) const;

  private:
    S const * x_;
  };

  /**
   * @class Inout_UB_String_Argument_T
   *
   * @brief Template class for INOUT unbounded (w)string argument.
   *
   */
  template<typename S>
  class Inout_UB_String_Argument_T : public Mutable_Argument_T<S *&>
  {
  public:
    Inout_UB_String_Argument_T (S *& x);

    virtual CORBA::Boolean marshal (TAO_OutputCDR &);
    virtual CORBA::Boolean demarshal (TAO_InputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_param (Dynamic::Parameter &);
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    virtual S *& arg (void);

  private:
    S *& x_;
  };

  /**
   * @class Out_UB_String_Argument_T
   *
   * @brief Template class for INOUT unbounded (w)string argument.
   *
   */
  template<typename S, typename S_out>
  class Out_UB_String_Argument_T : public Mutable_Argument_T<S *&>
  {
  public:
    Out_UB_String_Argument_T (S_out & x);

    virtual CORBA::Boolean demarshal (TAO_InputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_param (Dynamic::Parameter &);
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    virtual S *& arg (void);

  private:
    mutable S *& x_;
  };

  /**
   * @class Ret_UB_String_Argument_T
   *
   * @brief Template class for return stub value of ub (w)string argument.
   *
   */
  template<typename S, typename S_var>
  class Ret_UB_String_Argument_T : public Mutable_Argument_T<S *&>
  {
  public:
    Ret_UB_String_Argument_T (void);

    virtual CORBA::Boolean demarshal (TAO_InputCDR &);
#if TAO_HAS_INTERCEPTORS == 1
    virtual void interceptor_result (CORBA::Any *);
#endif /* TAO_HAS_INTERCEPTORS == 1 */
    virtual S *& arg (void);

    S * excp (void);
    S * retn (void);

  private:
    S_var x_;
  };

  /**
   * @struct UB_String_Tag
   *
   * @brief Struct for unbounded (w)string arguments id tag.
   *
   */
  struct TAO_Export UB_String_Tag {};

  /**
   * @struct UB_String_Arg_Traits_T
   *
   * @brief Template class for argument traits of unbounded (w)strings.
   *
   */
  template<typename T, typename T_var, typename T_out>
  struct UB_String_Arg_Traits_T
  {
    typedef T *                                         ret_type;
    typedef T const *                                   in_type;
    typedef T *&                                        inout_type;
    typedef T_out                                       out_type;

    typedef In_UB_String_Argument_T<T>                  in_arg_val;
    typedef Inout_UB_String_Argument_T<T>               inout_arg_val;
    typedef Out_UB_String_Argument_T<T,T_out>           out_arg_val;
    typedef Ret_UB_String_Argument_T<T,T_var>           ret_val;

    typedef Const_Argument_T<in_type>                   in_arg_base;
    typedef Mutable_Argument_T<inout_type>              inout_arg_base;
    typedef Mutable_Argument_T<inout_type>              out_arg_base;
    typedef Mutable_Argument_T<inout_type>              ret_base;


    typedef UB_String_Tag                               idl_tag;
  };
}

#if defined (__ACE_INLINE__)
#include "tao/UB_String_Argument_T.inl"
#endif /* __ACE_INLINE__ */

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "tao/UB_String_Argument_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("UB_String_Argument_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#include /**/ "ace/post.h"

#endif /* TAO_UB_STRING_ARGUMENT_T_H */
