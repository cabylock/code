const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost:27017/Todo')
.then(() => console.log('Connected to MongoDB...'))


const todoSchema = new mongoose.Schema(
{
   value: String,
   checked: Boolean
}
)


const collection = mongoose.model('todo', todoSchema);



module.exports = collection;










