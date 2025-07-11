var createHelloWorld = function() {
    var func='Hello World'
    return function(...arg) {
        return func;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */