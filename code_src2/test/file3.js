function log(target, name, descriptor) {
    const original = descriptor.value;
    descriptor.value = function(...args) {
      console.log(`Calling ${name} with arguments: ${args}`);
      return original.apply(this, args);
    };
    return descriptor;
  }
  
  class Calculator {
    add(a, b) {
      return a + b;
    }
  }
  
  // Áp dụng decorator
  Object.defineProperty(Calculator.prototype, 'add', log(Calculator.prototype, 'add', Object.getOwnPropertyDescriptor(Calculator.prototype, 'add')));
  
  // Tạo instance và sử dụng
  const calc = new Calculator();
(calc.add(2, 3)); // Sẽ log: "Calling add with arguments: 2,3" và trả về 5