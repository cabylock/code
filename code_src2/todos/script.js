


function add_li()
{     if(document.getElementById("input").value != "")
     {   var value = document.getElementById("input").value; // lấy value từ ô input
      var ul = document.getElementById("list"); // lấy thẻ ul
      
      var li = document.createElement("li"); // tạo thẻ li
      var checkbox = document.createElement("input"); // tạo thẻ input
      checkbox.type = "checkbox"; // gán type cho thẻ input
      checkbox.id = "checkbox"; // gán id cho thẻ input
      
      var span = document.createElement("span"); // tạo thẻ span
      span.contentEditable = "true"; // gán thuộc tính contentEditable cho thẻ span
      
      
      var deleteButton = document.createElement("button"); // tạo thẻ button
      deleteButton.textContent = "Delete"; // gán value vào thẻ button
      deleteButton.className = "delete"; // gán id cho th
    
        checkbox.onclick = function() { li.style.textDecoration = checkbox.checked ? "line-through" : "none" } // tạo sự kiện khi click vào checkbox
        span.textContent = value; // gán value vào thẻ span
        deleteButton.onclick = function() { li.remove(); }// tạo sự kiện khi click vào button
        ul.appendChild(li); // thêm thẻ li vào thẻ ul
        li.appendChild(checkbox); // thêm thẻ input vào thẻ ul
        li.appendChild(span); // thêm thẻ span vào thẻ li
      li.appendChild(deleteButton); // thêm thẻ button vào thẻ ul
      document.getElementById("input").value="" 

}
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





