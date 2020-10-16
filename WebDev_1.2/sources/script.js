let taskTable = document.querySelector(".main-body");
let addButton = document.getElementById("addButton");
let dialogueWindow = document.querySelector(".dialogue-window");
let oppacityBackground = document.querySelector(".oppacity");
let saveButton = document.getElementById("saveButton");
let undoButton = document.getElementById("undoButton");
let taskArray = document.querySelectorAll(".body-task");
let taskDescriptionInput = document.getElementById("task-description");
let prioritizeCheckbox = document.getElementById("prioritize");
let checkboxesArray = document.querySelectorAll(".task-status");
let transitArray = [];
let counter=0;
let readyButton = document.getElementById("#ready");
addButton.addEventListener("click", () => {
  dialogueWindow.classList.toggle("hide");
  oppacityBackground.classList.toggle("hide");
});

saveButton.addEventListener("click", () => {
  dialogueWindow.classList.toggle("hide");
  oppacityBackground.classList.toggle("hide");
  counter++;
  let taskDescription = taskDescriptionInput.value;
  let newElem = document.createElement("div");
  newElem.classList.add("body-task");
  taskDescriptionInput.value = "";
  if (prioritizeCheckbox.checked) {
    newElem.innerHTML = `
    <div class="task_info-panel">
      <label for="task-status" class="task-name">
      <input type="checkbox" class="task-status" id = "task-status" />
       ${taskDescription}
    </label>
      <span>
        <img src="./sources/highpriority.png">
    </span>
    </div>
        <button onclick = "parentNode.remove()"  class ="deleteButton" />`;
  } else {
    newElem.innerHTML = `
    <div class="task_info-panel">
      <label for="task-status" class="task-name">
      <input type="checkbox" class="task-status" id = "task-status" />
      ${taskDescription}
    </label>
    </div>
        <button onclick = "parentNode.remove()"  class ="deleteButton" />`;
  }
  taskDescriptionInput.value = "";
  prioritizeCheckbox.checked = false;
  taskTable.append(newElem);
  // checkboxesArray = document.querySelectorAll(".task-status");
  // transitArray.push(checkboxesArray[counter]);
  // console.log(transitArray[counter]);
  // console.log(checkboxesArray[counter]);
  // checkboxesArray[counter].addEventListener("click", () => {
  //   taskDescription.parentNode.classList.toggle("crossline-style");
  //   console.log(counter);
  // });
});
  for (let i = 0; i < checkboxesArray.length; i++) {
    transitArray.push(checkboxesArray[i]);
    checkboxesArray[i].addEventListener("click", () => {
      transitArray[i].parentNode.classList.toggle("crossline-style");
    });
  }



undoButton.addEventListener("click", () => {
  dialogueWindow.classList.toggle("hide");
  oppacityBackground.classList.toggle("hide");
});
