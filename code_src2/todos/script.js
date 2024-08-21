function add_li()
{     var value = document.getElementById("input").value; // lấy value từ ô input
      var ul = document.getElementById("list"); // lấy thẻ ul
      
      var li = document.createElement("li"); // tạo thẻ li
      var deleteButton = document.createElement("button"); // tạo thẻ button
      li.textContent = value; // gán value vào thẻ li
      deleteButton.textContent = "Delete"; // gán value vào thẻ button
      deleteButton.className = "delete"; // gán id cho th
      deleteButton.onclick = function() { li.remove(); deleteButton.remove() }// tạo sự kiện khi click vào button
      ul.append(li); // thêm thẻ li vào thẻ ul
      li.append(deleteButton); // thêm thẻ button vào thẻ ul

     
}


function press_enter(event) 
{
   if(event.key === 'Enter')
   {
      add_li();
   }
}

function addTodo() 
{     
      add_li()
}





