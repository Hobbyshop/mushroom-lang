![logo](./logo.png)

### Example code
```
func main() {
    var name: string = "Bob"
    say_something(name, "Hello World")

    if (name == "Bob") {
        println("Hello Bob")
    }
    
    var integer_variable: i32 = 8;
    switch (integer_variable) {
        case 5 {
            break;
        },
        case 10, 9, 8 {
            break;
        },
        case {      // will trigger if no other case is triggered
            break;
        }
    }
    
}

func say_something(name: string, text: string) {
    println("${name} said, ${text}")
}

func do_maths(x: int, y: int) int {
    return x + y
}
```

### Feature Roadmap
* everything

