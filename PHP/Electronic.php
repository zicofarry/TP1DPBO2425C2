<?php

// Class Electronic
class Electronic {
    // Atribut
    public $id = 0;
    public $name = '';
    public $category = '';
    public $price = 0;
    public $photo = '';

    // Constructor
    public function __construct($id = 0, $name = '', $category = '', $price = 0, $photo = '') {
        $this->id = $id;
        $this->name = $name;
        $this->category = $category;
        $this->price = $price;
        $this->photo = $photo;
    }

    // SETTER & GETTER
    public function setId($id) { $this->id = $id; }
    public function getId() { return $this->id; }

    public function setName($name) { $this->name = $name; }
    public function getName() { return $this->name; }

    public function setCategory($category) { $this->category = $category; }
    public function getCategory() { return $this->category; }

    public function setPrice($price) { $this->price = $price; }
    public function getPrice() { return $this->price; }

    public function setPhoto($photo) { $this->photo = $photo; }
    public function getPhoto() { return $this->photo; }
}

?>