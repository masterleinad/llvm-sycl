; NOTE: Assertions have been autogenerated by utils/update_test_checks.py UTC_ARGS: --check-attributes
; RUN: opt < %s -passes=function-attrs -S | FileCheck %s

define i32 @f() {
; CHECK: Function Attrs: nofree readonly
; CHECK-LABEL: @f(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    [[TMP:%.*]] = call i32 @e()
; CHECK-NEXT:    ret i32 [[TMP]]
;
entry:
  %tmp = call i32 @e( )
  ret i32 %tmp
}

declare i32 @e() readonly

