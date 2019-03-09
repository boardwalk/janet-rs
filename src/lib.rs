#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(non_upper_case_globals)]

include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

#[cfg(test)]
mod test {
    use super::*;
    use std::ffi::CString;
    use std::ffi::CStr;
    use std::ptr::null_mut;

    #[test]
    fn test_version() {
        let janet_version = CStr::from_bytes_with_nul(JANET_VERSION)
            .unwrap()
            .to_string_lossy();
        assert_eq!(janet_version, env!("CARGO_PKG_VERSION"));
    }

    #[test]
    #[allow(clippy::float_cmp)]
    fn test_dostring() {
        unsafe {
            assert_eq!(janet_init(), 0);

            let source = CString::new("(+ 3 4)").unwrap();
            let file = CString::new(file!()).unwrap();
            let mut out = janet_sys_wrap_nil();
            assert_eq!(janet_dostring(janet_core_env(null_mut()), source.as_ptr(), file.as_ptr(), &mut out), 0);
            assert_eq!(janet_sys_type(out), JanetType_JANET_NUMBER);
            assert_eq!(janet_sys_unwrap_number(out), 7.0);

            janet_deinit();

        }
    }

    #[test]
    fn test_marshal() {
        unsafe {
            assert_eq!(janet_init(), 0);

            let source = CString::new("(fiber/new (fn [] (yield 1) (yield 2) 3))").unwrap();
            let file = CString::new(file!()).unwrap();
            let mut fiber_1 = janet_sys_wrap_nil();
            assert_eq!(janet_dostring(janet_core_env(null_mut()), source.as_ptr(), file.as_ptr(), &mut fiber_1), 0);
            assert_eq!(janet_sys_type(fiber_1), JanetType_JANET_FIBER);

            let mut res_1 = janet_sys_wrap_nil();
            assert_eq!(janet_continue(janet_sys_unwrap_fiber(fiber_1), janet_sys_wrap_nil(), &mut res_1), JanetSignal_JANET_SIGNAL_YIELD);

            let buf = janet_buffer(1024);
            janet_marshal(buf, fiber_1, null_mut(), 0);
            assert!((*buf).count != 0);
            let fiber_2 = janet_unmarshal((*buf).data, (*buf).count as usize, 0, null_mut(), null_mut());
            janet_buffer_deinit(buf);

            for i in 1..3 {
                let sig = if i < 2 { JanetSignal_JANET_SIGNAL_YIELD } else { JanetSignal_JANET_SIGNAL_OK };
                let mut res_1 = janet_sys_wrap_nil();
                assert_eq!(janet_continue(janet_sys_unwrap_fiber(fiber_1), janet_sys_wrap_nil(), &mut res_1), sig);
                let mut res_2 = janet_sys_wrap_nil();
                assert_eq!(janet_continue(janet_sys_unwrap_fiber(fiber_2), janet_sys_wrap_nil(), &mut res_2), sig);
                assert_eq!(janet_equals(res_1, res_2), 1);
            }
        }
    }
}
