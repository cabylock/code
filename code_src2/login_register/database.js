const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost:27017/user')
.then(() => console.log('Connected to MongoDB'))
.catch(err => console.error('Could not connect to MongoDB', err));


let userSchema = new mongoose.Schema(
      {
            name: String,
            age: Number,
            male: Boolean


      },
      {
            collection: 'user'
      }

);


let collection = mongoose.model( 'user',userSchema);

module.exports = collection;











