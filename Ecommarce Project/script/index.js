const menuIcon = document.getElementById("menu-icon");
const menu = document.getElementById("menu");

menuIcon.addEventListener("click", () => {
    if (menu.classList.contains("hidden")) {
        menu.classList.remove("hidden");
    } else {
        menu.classList.add("hidden");
    }
});
