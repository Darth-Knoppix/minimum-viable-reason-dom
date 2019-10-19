/* Interacting with the console is as easy as JS */
let message = "Log like this!";
Js.log(message);

/* The dom is a little harder */

/* Get out element, we use Js.Nullable.t in case it doesn't exist */
let outputEl: Js.Nullable.t(Dom.node) = [%bs.raw
  {| document.getElementById("output") |}
];

/* Convert to an option type to make it easier to work with */
let maybeEl = outputEl |> Js.Nullable.toOption;

switch (maybeEl) {
| Some(_) =>
  %bs.raw
  {| outputEl.innerText = "minimum viable Reason" |}

| None => Js.log("Couldn't find the output element")
};