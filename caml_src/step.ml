(* Copyright (C) 2017 Sio Kreuzer. All Rights Reserved. *)

(*
TODO:
    - make an object to store game's state
    - declare object on global scope as mutable in some way
    - go through S.T.A.L.K.E.R. SoC wiki and make sure we can replicate described gameplay from definitions in files/SQLite3 dbs
    - make the game's state storable/loadable to/from an SQLite3 db
*)

(*
let game_state = ref GameState;; (* TODO: need one of these types'a objects. *)

NOTE: it should be possible to have step take a GameState and return another one to C++ code.
*)

let init () =
    Printf.printf "Initializing Game module...\n";
    flush stdout;;

let shutdown () =
    Printf.printf "Shutting down Game module...\n";
    flush stdout;;

let step () =
    (* Printf.printf "bla\n"; *)
    flush stdout;;

(* main/init *)
let () =
    Callback.register "init_fn" init;
    Callback.register "shutdown_fn" shutdown;
    Callback.register "step_fn" step;;
