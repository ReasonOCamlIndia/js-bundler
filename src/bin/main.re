let parse = source => {
  let parse_options =
    Some(
      Parser_env.{
        components: false,
        enums: false,
        esproposal_decorators: false,
        types: false,
        use_strict: false,
        module_ref_prefix: None,
        module_ref_prefix_LEGACY_INTEROP: None,
      },
    );
  Parser_flow.program(source, ~parse_options);
};

let source = {|
   console.log("Hello, World.");
|};

let print = ast => {
  Flow_ast.(Program.show(Loc.pp, Loc.pp, ast));
};

let (ast, _errors) = parse(source);
ast |> print |> print_endline;
