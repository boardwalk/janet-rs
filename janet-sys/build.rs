use std::env;
use std::path::PathBuf;
use std::process::Command;

fn main() {
    let janet_dir = PathBuf::from(env::var("CARGO_MANIFEST_DIR").unwrap())
        .join("vendor")
        .join("janet");

    // Make janet.c and janet.h
    Command::new("make")
        .arg("amalg")
        .current_dir(&janet_dir)
        .status()
        .expect("Failed to make amalgamation");

    // Build it
    cc::Build::new()
        .file(janet_dir.join("build").join("janet.c"))
        .file("wrapper.c")
        .compile("janet");

    // Generate bindings for it
    let out_dir = PathBuf::from(env::var("OUT_DIR").unwrap());

    let bindings = bindgen::Builder::default()
        .header(janet_dir.join("build").join("janet.h").to_str().unwrap())
        .header("wrapper.h")
        .generate()
        .expect("Unable to generate bindings");

    bindings
        .write_to_file(out_dir.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
